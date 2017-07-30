#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;

int INF = 1 << 30;
int t[100];
int dp[300][100];
int has_train[300][100][2];
int main(void)
{
    int N;
    int kase;
    while(1)
    {
        cin >> N;
        if(N == 0) break;
        for(int i = 0; i < 300; i++)
            for(int j = 0; j < 100; j++)
            {
                has_train[i][j][0] = 0;
                has_train[i][j][1] = 0;
            }
        for(int i = 0; i <= 0; i++)
            for(int j = 0; j < 100; j++)
                dp[i][j] = INF;
        dp[0][0] = 0;
           
        int T;
        cin >> T;
        for(int i = 1; i < N; i++) cin >> t[i];
        t[0] = 0;
        t[N] = 0; // for convinent
        int M1;
        cin >> M1;
        int delay;
        int sum;
        for(int i = 0; i < M1; i++)
        {
            cin >> delay;
            sum = 0;
            for(int j = 0; j < N; j++ )
            {
                sum += t[j];
                has_train[delay + sum][j][0] = 1;
            }
        }
        int M2;
        cin >> M2;
        for(int i = 0; i < M2; i++)
        {
            cin >> delay;
            sum = 0;
            for(int j = N - 1; j >= 0; j-- )
            {
                sum += t[j + 1];
                has_train[delay + sum][j][1] = 1;
            }
        }

        //for(int i = 1; i <= T; i++)
        //{
        //    for(int j = 0; j < N; j++)
        //        cout << dp[i][j] << " ";
        //    cout << endl;
        //}
        for(int i = 1; i <= T; i++)
        {
            for(int j = 0; j < N; j++)
            {
                dp[i][j] = dp[i - 1][j] + 1;
                //cout << "(" << i << ", " << j << ")" << ' ' << dp[i][j] << endl;  
                if(has_train[i][j][0] && j - 1 >= 0 && i >= t[j] )
                    dp[i][j] = min(dp[i][j], dp[i - t[j]][j - 1]);

                if(has_train[i][j][1] && j + 1 < N && i >= t[j + 1] )
                    dp[i][j] = min(dp[i][j], dp[i - t[j + 1]][j+1]);
            }
        }
        
        int ans =  dp[T][N - 1];
        kase++;
        cout << "Case Number " << kase << ": ";
        if(ans >= INF) cout << "impossible" << endl;
        else           cout << ans << endl;




    }

}
