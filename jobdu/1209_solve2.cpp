#include<cstdio>
#include<iostream>
#include<string.h>
using namespace std;

const int INF = 999;
int v[30];
int vis[30][105];
int d[30][105];
int min_(int a, int b);
int dp(int i, int j);
int main(void)
{
    int M;
    int N;
    while(cin >> M) 
    {
        cin >> N;
        memset(v, 0, sizeof(v));
        memset(d, INF, sizeof(d));
        memset(vis, 0, sizeof(vis));
        for(int i = 1; i <= N; i++)
            cin >> v[i];
        int ans = dp(N, M);
        if (ans >= INF) cout << "0" << endl;
        else            cout << ans << endl;
    }
}

int min_(int a, int b)
{
    return a <= b ? a : b;
}

int dp(int i, int j)
{
   if(j <= 0) return 0;
   if(i <= 0) return INF;
   if (vis[i][j]) return d[i][j];
   vis[i][j] = 1;
   //cout  <<  "i:" << i << " j:" << j <<  " vi: " << v[i] << endl;
   if(j >= v[i]) return d[i][j] = min_(dp(i - 1, j - v[i]) + 1, dp(i - 1, j));
   else          return INF;
}
