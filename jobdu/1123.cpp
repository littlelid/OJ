#include<cstdio>
#include<iostream>
#include<string.h>
using namespace std;

int d[105][1005];
int v[105];
int w[105];
int main(void)
{
    int t, m;
    while(cin >> t >> m)
    {
        memset(d, 0, sizeof(d));

        memset(v, 0, sizeof(v));
        memset(w, 0, sizeof(w));
        for(int i = 1; i <= m; i++)
            cin >> w[i] >> v[i];

        for(int i = 1; i <=m; i++)
        {
            for(int j = 0; j <= t; j++)
            {
                d[i][j] =  ( i == 1 ? 0 : d[i - 1][j]);
                if(j >= w[i])
                {
                    if(d[i - 1][j - w[i]] + v[i] > d[i][j]) 
                        d[i][j] = d[i - 1][j - w[i]] + v[i];
                }
            }
        }
        cout << d[m][t] << endl;

    }
}
