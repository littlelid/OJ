#include<cstdio>
#include<iostream>
#include<map>
using namespace std;

int edges_id[64];
char op[64];
int vexs[64];
int N;
map<long long, int> dp_max;
map<long long, int> dp_min;
int dfs(int edges_id[], int length, int flag);
int left_vex(int id);
int right_vex(int id);
long long encode(int edges_id[], int length);
int compute(int a, int b, char o);

int main(void)
{
    while(cin >> N) 
    {
        for (map<long long, int>::iterator i = dp_max.begin(); i != dp_max.end(); /*i++*/)  
            dp_max.erase(i++);  
        for (map<long long, int>::iterator i = dp_min.begin(); i != dp_min.end(); /*i++*/)  
            dp_min.erase(i++);  
        
        for(int i = 0; i < N; i++)
        {
            edges_id[i] = i;
            cin >> op[i];
            cin >> vexs[i];
        }
            
        int cuts[64];
        int ans = -(1 << 20);
        int cut;
        for(int i = 0; i < N; i++)
        {
            cut = N - 1 - i;
            if(i) 
            {
                for(int i = N - 1; i >= 0; i--)
                {
                    edges_id[i + 1] = edges_id[i];
                    //op[i + 1] = op[i];
                    //vexs[i + 1] = vexs[i];
                }
                edges_id[0] = edges_id[N]; //, op[0] = op[N], vexs[0] = vexs[N];
            }
           /* 
            for(int i = 0; i < N; i++) 
                cout << edges_id[i] << ' '; 
            cout << endl;
            for(int i = 0; i < N; i++) 
                cout << op[i] << ' '; 
            cout << endl;
            for(int i = 0; i < N; i++) 
                cout << vexs[i] << ' '; 
            cout << endl;
           */

            int temp = dfs(edges_id, N - 1, 1);
            //cout << temp  << ' ' << cut << endl;
            cuts[cut] = temp;
        }
        int  max_ans = -(1 << 20);
        for(int i = 0; i < N; i++)
            if(cuts[i] > max_ans) max_ans = cuts[i];
        cout << max_ans << endl;
        int first = 1;
        for(int i = 0; i < N; i++)
        {
            if(cuts[i] == max_ans)
            {
                if(first){first  = 0; cout << i+1;}
                else cout << ' ' << i + 1;
            }
        }
        cout << endl;
        

        //cout << "*******" << endl;

    }
    


}
int dfs(int edges[], int length, int flag)
{
    long long code = encode(edges, length);
    char o;
    if(flag && dp_max.count(code)) 
    {
        /*
        cout << "get max_id: ";
        for(int i = 0; i < length; i++)
            cout << edges[i] << ' ';
        cout <<"  =  " << dp_max[code] << endl;
        */
        return dp_max[code];
    }
    if(!flag && dp_min.count(code)) 
    {
        /*
        cout << "get min_id: ";
        for(int i = 0; i < length; i++)
            cout << edges[i] << ' ';
        cout << " = " << dp_min[code] << endl;
        */
        return dp_min[code];
    }

    int left, right;
    if(length == 1) 
    {
        o = op[edges[0]];
        left = left_vex(edges[0]); 
        right = right_vex(edges[0]); 
        dp_min[code] = dp_max[code] = compute(left, right, o);
        
        //for(int j = 1; j <= N - 1 - length; j++) cout <<'\t';
        //cout << '*' << left << o << right << endl; 
        return dp_min[code];
    }

    int ans; 
    if(flag) ans = - (1 << 20);
    else     ans = 1 << 20;
    int temp0, temp1;
    int left_max, left_min, right_max, right_min;
    for(int i = 0; i < length; i++)
    {
        int id = edges[i];
        
        char o = op[id];
        if(!i) left_min = left_max = left_vex(edges[i]);
        else  
        {
            if(o == 't')
            {
                if(flag) left_max = dfs(edges, i, 1);
                else left_min = dfs(edges, i, 0);
            }
            if(o == 'x')
            {
                left_min = dfs(edges, i, 0);
                left_max = dfs(edges, i, 1);
            }
        }            

        if(i == length - 1) right_max = right_min = right_vex(edges[i]);
        else  
        {
            if(o == 't')
            {
                if(flag) right_max = dfs(edges + i + 1, length - 1 - i, 1);
                else right_min = dfs(edges + i + 1, length - 1 - i, 0);
            }
            if(o == 'x')
            {
                right_min = dfs(edges + i + 1, length - 1 - i, 0);
                right_max = dfs(edges + i + 1, length - 1 - i, 1);
            }
        }
        
        if(flag)
        {
           if(o == 't')
            {
                temp0 = compute(left_max, right_max, o);
                if(temp0 > ans)  ans = temp0;
            }
           if(o == 'x')
            {
                 temp0 = compute(left_max, right_max, o); 
                 temp1 = compute(left_min, right_min, o); 
                 if(temp0 > ans) ans = temp0;
                 if(temp1 > ans) ans = temp1;
            }
        }
        else
        {
            if(o == 't')
            {
                temp0 = compute(left_min, right_min, o);
                if(temp0 < ans)  ans = temp0;
            }
            if(o == 'x')
            {
                 temp0 = compute(left_max, right_max, o); 
                 temp1 = compute(left_min, right_min, o); 

                 if(temp0 < ans) ans = temp0;
                 if(temp1 < ans) ans = temp1;
            }

        }
    }
    if(flag)
    {
        dp_max[code] = ans;
        //cout << "save max_id: ";
        //for(int i = 0; i < length; i++)
        //    cout << edges[i] << ' ';
       // cout << "= " << dp_max[code] << endl;
    }
    else
    {
        dp_min[code] = ans;
        //cout << "save min_id: ";
        //for(int i = 0; i < length; i++)
        //    cout << edges[i] << ' ';
        //cout << "= " << dp_min[code] << endl;
    }

    return ans;
}

int left_vex(int id)
{
    //cout << "**" << vexs[(id - 1 + N) % N] << endl;
    //cout << (id - 1 + N) % N << endl;
    return vexs[(id - 1 + N) % N];
}

int right_vex(int id)
{
    return vexs[id];
}

long long encode(int edges_id[], int length)
{
    long long code = 0;

    for(int i = 0; i < length; i++)
    {
        long long temp = 1;
        code += (temp << edges_id[i]);
        //cout << code << "after add: " << (1 << edges_id[i]) << endl;
    }
    /*
    if(code < 0)
    {
        for(int i = 0; i < length; i++)
        {
            cout << edges_id[i] << ' '; 
        }
        cout << endl;

        cout << '\t' << code << endl;
    }
    */
    //cout << '\t' << code << endl;
    return code;
}

int compute(int a, int b, char o)
{
    if(o == 't') return a+b;
    if(o == 'x') return a*b;
    return 1;
}
