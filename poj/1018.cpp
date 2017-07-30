#include<cstdio>
#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;

int dp[105][20000];
int b[105];
int p[105];
int main(void)
{
    int t;
    cin >> t ;
    while(t--)
    {
        memset(dp, -1, sizeof(dp));
        int n;
        cin >> n;
        int maxb = 0;
        for(int i = 1; i <= n; i++)
        {
            int m;
            int maxv = 0;
            cin >> m;
            for(int j = 1; j <= m; j++)
            {
                cin >> b[j] >> p[j];
                maxv = max(maxv, b[j]);
            }
            maxb = max(maxb, maxv);
            if(i == 1)
            {
                for(int j = 1; j <= m; j++)
                    dp[i][b[j]] = p[j];
            }
            //cout << maxv << endl;
            for(int v = 0; v <= maxb; v++)
            {
                if(dp[i-1][v] == -1) continue;
                for(int j = 1; j <= m; j++)
                {
                    int mb = min(v, b[j]);
                    //if(i == 3) cout << "mb:" << mb << endl; 
                    //if(i == 3 && mb == 120) cout <<"dp:" << dp[i][mb] << endl;
                    if(dp[i][mb] == -1)
                    {
                        dp[i][mb] = dp[i-1][v] + p[j];
                    }
                    else
                    {
                        dp[i][mb] = min(dp[i][mb], dp[i-1][v] + p[j]);
                    }
                }
            }
        
        }
        double max_ans = 0.0;
        for(int i = n; i <=n; i++)
        {
            for(int j = 1; j <= maxb; j++)
            {
                if(dp[i][j] != -1)
                {

                    //cout << i << ' ' << j << ": " << dp[i][j] << ' ' << 1.0*j /dp[i][j] << '\t';
                    
                    max_ans = max(max_ans,  1.0*j /dp[i][j]);
                    //cout << max_ans << endl;

                }
            }
            //cout << endl;
        }
        printf("%.3f\n", max_ans);
    }

}
