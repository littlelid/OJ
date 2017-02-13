#include<cstdio>
#include<vector>
#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;


bool comp[105][105];

struct node{
    int x;
    bool operator < (const node& o) const   //intend
    {
        return comp[o.x][x];

    }

};


int main(void)
{
    while(1)
    {
        int n, m;
        cin >> n >> m;
        if(n == 0 && m == 0) break;
        memset(comp, false, sizeof(comp));

        node ans[n + 1];
        for(int i = 1; i <= n; i++)
        {
            ans[i].x = i;
        }

        for(int i = 1; i <= m; i++)
        {
            int p, q;
            cin >> p >> q;
            comp[p][q] = true;
        }

        sort(ans+1, ans + n + 1);

        int flag = 1;
        for(int i = n; i >=1; i--)
        {
            if(flag)
            {
                flag = 0;
                cout << ans[i].x;
            }
            else cout << " " << ans[i].x;
        }

        cout << endl;
    }

}
/*

*/
