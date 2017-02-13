#include<cstdio>
#include<vector>
#include<iostream>
#include<string.h>
#include<algorithm>
#include<stack>
using namespace std;


int n, m;
int G[105][105];
int visit[105];
int inx;
int ans[105];

bool dfs(int u);
bool toposort();

int main(void)
{
    while(1)
    {

        cin >> n >> m;
        if(n == 0 && m == 0) break;

        memset(G, 0, sizeof(G));
        memset(visit, 0, sizeof(visit));



        for(int i = 1; i <= m; i++)
        {
            int p, q;
            cin >> p >> q;
            G[p][q] = 1;
        }

        toposort();



        int flag = 1;
        for(int i = 1; i <= n; i++)
        {
            if(flag)
            {
                flag = 0;
                cout << ans[i];
            }
            else cout << " " << ans[i];
        }

        cout << endl;
    }

}

bool dfs(int u)
{
    visit[u] = -1;

    for(int i = 1; i <= n; i++)
    {
        if(G[u][i])
        {
            if(visit[i] == -1)
            {
                return false;
            }

            if(visit[i] == 0)
            {
                if(!dfs(i)) return false;
            }

        }

    }

    visit[u] = 1;
    ans[inx] = u; inx--;

    return true;
}

bool toposort()
{
    inx = n;
    for(int i = 1; i <= n; i++)
    {
        if(!visit[i])
        {
            bool nocycle = dfs(i);
            if(!nocycle) return false;
        }
    }

    return true;
}

