#include<cstdio>
#include<iostream>
#include<vector>
#include<map>
using namespace std;

typedef vector<int> v_int;
v_int son[1005];
int bfs[1005];
int dfs[1005];
int dfs_inx[1005];
int main(void)
{
    int n;

    while(cin >> n)
    {
        map<int, v_int> ans;  
        
        for(int i = 1; i <= n; i++)
        {
            v_int t;
            ans[i] = t;
        }
       
        int temp;
        for(int i = 1; i <= n; i++)
        {
            cin >> temp;
            bfs[i] = temp;
        }
        
        for(int i = 1; i <= n; i++)
        {
            cin >> temp;
            dfs[i] = temp;
            dfs_inx[dfs[i]] = i;
        }
        
        
        int cursor = 2;             //***
        
        
        v_int last_layer;
        
        last_layer.push_back(bfs[1]);
        
        while(cursor <= n)
        {
            v_int new_layer;    
            int flag = 1;
            for(int i = 0; i < last_layer.size(); i++)
            {
                int first = 1;    
                //cout << "here now = "  << last_layer[i] << endl;
                while(1)
                {
                    //cout << "\t*1*" << endl;
                    if(cursor > n) break;
                    //cout << "\t*2*" << endl;
                    if(!first && bfs[cursor] < bfs[cursor - 1]) break;
                    first = 0;
                    //cout << "\t*3*" << endl;
                    if(!flag && dfs_inx[bfs[cursor]] < dfs_inx[bfs[cursor - 1]]) break;
                    flag = 0;
                    //cout << "\t*4*" << endl;
                    new_layer.push_back(bfs[cursor]);
                    //cout << "\tpush: " << bfs[cursor] << endl;

                    int p = i;
                    //cout << "\t\t" << p << endl;
                    while(p < last_layer.size() && dfs_inx[last_layer[p]] < dfs_inx[bfs[cursor]]) p++;
                    //cout << "\t\t" << p << endl;
                    p -= 1;
                    //cout << "\t\t" << p << endl;
                    ans[last_layer[p]].push_back(bfs[cursor]);
                    //cout << "\t" << last_layer[p] << " -> " << bfs[cursor] << endl; 

                    cursor++;
                    
                    
                } 
                if(cursor > n) break;
            }
            
            //cout << "new_layer:\n\t";
            //for(int j = 0; j < new_layer.size(); j++) cout << new_layer[j] << " ";
            //cout << endl << endl;

            //cout << cursor << endl;
            
            last_layer = new_layer;
        }
        for(int i = 1; i <= n; i++)
        {
            cout << i << ":";
            for(int j = 0; j < ans[i].size(); j++)
            {
                cout << " " << ans[i][j];
            }
            cout << endl;
        }
    }
}