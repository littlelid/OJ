#include<cstdio>
#include<iostream>
#include<stdlib.h>
using namespace std;

int max_(int a, int b);
int main(void)
{
    int W, N;
    while(cin >> W >> N)
    {
        int d[N + 1][W + 1];
        memset(d, 0, sizeof(d));
        int w[N+1], v[N+1];
        for(int i = 1; i <= N; i++)
        {
            cin >> w[i] >> v[i];
        }
        
        for(int i = 1; i <= N; i++)
        {
            //cout << w[i] << endl;
            for(int j = 0; j <= W; j++)
            {
                //if(j >= w[i])
                //    if(d[i][j] < d[i-1][j-w[i]] + v[i])
                //        d[i][j] = d[i-1][j-w[i]] + v[i];
                //cout << i-1 << ' ' << j << ' ' << d[i - 1][j] << " | " << i - 1 << ' ' << j-w[i] << ' ' << d[i-1][j-w[i]] << ' ' << v[i] << endl;
                if(j >= w[i])
                    d[i][j] = max_(d[i-1][j], d[i-1][j-w[i]] + v[i] );
                else
                    d[i][j] = d[i - 1][j];
                //cout << i << ' ' << j << ' ' << d[i][j] << endl;
            }
        }

        cout << d[N][W] << endl;
    }
}
int max_(int a, int b)
{
    return a > b ? a : b;
}
