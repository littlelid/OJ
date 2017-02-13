#include<cstdio>
#include<iostream>
#include<map>
using namespace std;

typedef map<int, int> map_int;


int main(void)
{
    int np;
    int nt;
    int kase = 0;
    while(1)
    {
        cin >> np;
        if(np == 0) break;

        map_int in[101];
        map_int out[101];
        int tokens[101];

        int token;
        for(int i = 1; i <= np; i++)
        {
            cin >> token;
            tokens[i] = token;
        }

        cin >> nt;
        for(int i = 1; i <= nt; i++)
        {
            int p;
            while(1)
            {
                cin >> p;
                if(p == 0) break;
                if(p < 0) 
                {
                    if(!in[i].count(-p)) in[i][-p] = 0;
                    in[i][-p]++;
                }
                if(p > 0) 
                {
                    if(!out[i].count(p)) out[i][p] = 0;
                    out[i][p]++;
                }
            }    
        }

        int live;
        int nf;
        int cnt = 0;
        map<int, int>::iterator it;
        cin >> nf;
        for(int t = 1; t <= nf; t++)
        {
            live = 0;
            int i;
            for(i = 1; i <= nt; i++)
            {
                int in_ok = 1;
                for(it = in[i].begin(); it != in[i].end(); it++)
                {
                    if(tokens[it->first] < it->second) { in_ok = 0; break;}
                }
                if(in_ok) { live = 1; break;}
            }
            if(live)
            {
                cnt++;
                for(it = in[i].begin(); it != in[i].end(); it++)
                {
                    tokens[it->first] -= it->second;
                }
                for(it = out[i].begin(); it != out[i].end(); it++)
                {
                    tokens[it->first] += it->second;
                }
            }
            else break;
            
        }
        
        kase++;
        if(live)
        {
            cout << "Case " << kase << ": still live after " << cnt <<" transitions" << endl;
        }
        else
        {
            cout << "Case " << kase << ": dead after " << cnt << " transitions" << endl;
        }
        cout << "Places with tokens: ";
        for(int i = 1; i <= np; i++)
        {
            if(tokens[i] > 0) cout << i << " (" << tokens[i] << ") "; 
        }
        cout << endl << endl;
    }
} 