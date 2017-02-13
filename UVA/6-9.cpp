#include<cstdio>
#include<stack>
#include<vector>
#include<sstream>
#include<iostream>
using namespace std;

int left_1(int p);
int left_3(int p);
int match(int i, int j);

typedef stack<string> pile;
pile piles[55];

int main(void)
{
    string s;
    cin >> s;
    while(1)
    {
        
        if(s == "#") break;

        for(int i = 0; i < 52; i++)
        {
            //cout << s << " " ;
            while(!piles[i].empty()) piles[i].pop();
            piles[i].push(s);
            cin >> s;
        }
        
        while(1)
        {
            int end = 1;
            for(int i = 0; i < 52; i++)
            {
                if(piles[i].empty()) continue;
                //cout << "i = " << i << endl;
                int l_1 = left_1(i);
                int l_3 = left_3(i);
                //printf("\tL3, L1: (%d, %d)\n", l_3, l_1); 
                //cout << "test i = " << i << endl;
                if(match(l_3, i))
                {
                    //printf("\tmatch l_3: (%d, %d)\n", l_3, i); 
                    end = 0;
                    string temp = piles[i].top(); 
                    piles[i].pop();
                    piles[l_3].push(temp);
                    //cout << "end i = " << i << endl << endl;;
                    break;
                }
                else if(match(l_1, i))
                {
                    //printf("\tmatch l_1: (%d, %d)\n", l_1, i);
                    end = 0;
                    string temp = piles[i].top(); 
                    piles[i].pop();
                    piles[l_1].push(temp);
                    //cout << "end i = " << i << endl << endl;;
                    break;
                }
                //cout << "end i = " << i << endl << endl;;
                
            }
            if(end) break;
        }
        
        
        vector<int> ans;
        for(int i = 0; i < 52; i++)
        {
            if(!piles[i].empty()) ans.push_back(piles[i].size());
        }
        if(ans.size() > 1) cout << ans.size() << " piles remaining:";
        else cout << ans.size() << " pile remaining:";
        for(int i = 0; i < ans.size(); i++)
        {
            cout << " " << ans[i];
        }
        cout << endl;
    }
}
int match(int i, int j)
{
    //printf("\t\tmatching %d %d\n", i, j);
    if(i == -1 || j == -1) return 0;
    
    if(piles[i].top()[0] == piles[j].top()[0]) return 1;
    if(piles[i].top()[1] == piles[j].top()[1]) return 1;
    
    return 0;
}

int left_1(int p)
{
    //printf("\t\tin left_1: start in %d\n", p);
    int l = p - 1;
    if(l < 0) return -1;
    while(piles[l].empty())
    {
        //printf(" %d", l);
        if(l - 1 < 0) return -1;
        l--;
    }
    //cout << endl;
    //printf("\t\treturn %d\n", l);
    return l;
    
}
int left_3(int p)
{
    int l = left_1(p);
    if(l == -1) return -1;
    l = left_1(l);
    if(l == -1) return -1;
    l = left_1(l);
    return l;
}