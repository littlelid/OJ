#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>
using namespace std;

struct edge
{
    int n1, n2, dis;
    edge(char n1, char n2, int dis):n1(n1), n2(n2),dis(dis){}
    bool operator < (const edge& other) const
    {
        return dis < other.dis;  
    }
};

int f[35];
int find(int i);
int main(void)
{
    int n;
    while(cin >> n)
    {
        if(!n) break;
        for(int i = 0; i < 30; i++)
        {
            f[i] = i;
        }
        vector<edge> edges;
        for(int i = 0; i < n - 1; i++)
        {
            string s; int k;
            cin >> s >> k;
            //cout << s << ' ' << k << endl;
            for(int j = 0; j < k; j++)
            {
                string e; int d;
                cin >> e >> d;
                //cout << '\t' << e << ' ' << d;
                edges.push_back(edge(s[0] - 'A', e[0] - 'A', d));
            }
            //cout << endl;
        }
        sort(edges.begin(), edges.end());
        
        int ans = 0;
        for(int i = 0; i < edges.size(); i++)
        {
            //for(int i = 0; i < 20; i++) cout << f[i] << ' ';
            //cout << endl;
            //cout << "HERE1 "  << ' ' << edges[i].n1 << ' ' << edges[i].n2 << endl;
            int f1 = find(edges[i].n1);
            int f2 = find(edges[i].n2);

            if(f1 != f2)
            {
                //cout << f1 <<  ' ' << f2  << ' ' << edges[i].dis << endl;
                ans += edges[i].dis;
                f[f1] = f2;
            }
        }
        cout << ans << endl;

    }


}

int find(int i)
{
    //cout << '\t' << i  << ' ' << f[i] << endl;
    return f[i] == i ? f[i] : f[i] = find(f[i]);
}
