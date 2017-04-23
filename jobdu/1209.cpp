#include<cstdio>
#include<iostream>
#include<string.h>
using namespace std;

const int INF = 999;
int dp[30][105];
int v[30];
int min_(int a, int b);
int main(void)
{
    int M;
    int N;
    while(cin >> M)
    {
        for(int i = 0; i < 30; i++)
            for(int j = 0; j < 105; j++)
                dp[i][j] = INF;
        memset(v, 0, sizeof(v));
        cin >> N;
        for(int i = 1; i <= N; i++)
        {
            cin >> v[i];
        }

        for(int i = 0; i <= N; i++)
           dp[i][0] = 0;

        for(int i = 1; i <= N; i++)
        {
            for(int j = 1; j <= M; j++)
            {
                if(j - v[i] >= 0)
                    dp[i][j] = min_( dp[i - 1][j - v[i]] + 1, dp[i - 1][j]);
                else
                    dp[i][j] = dp[i - 1][j];
              // cout << i << " " << j << ": " << dp[i][j] << endl;  
            }
        }

        if(dp[N][M] >= INF) cout << "0" << endl;
        else                cout <<  dp[N][M] << endl;
    }
}

int min_(int a, int b)
{
    return a <= b ? a : b;
}
