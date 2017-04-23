#include<cstdio>
#include<iostream>
#include<vector>
#include<string.h>
using namespace std;

long long L1, L2, L3, C1, C2, C3;
const long long  INF  = 1 < 30;
long long cost(long long dis);
int main(void)
{
    int A, B;
    int N;
    while(cin >> L1)
    {
        cin >> L2 >> L3 >> C1 >> C2 >> C3;
        cin >> A >> B;
        cin >> N;
        long long l[N + 5];
        l[1] = 0;
        for(int i = 2; i <= N; i++)
            cin >> l[i];
        
        long long dp[N + 5];
        memset(dp, INF, sizeof(dp));
        dp[A] = 0;
        for(int i = A; i < B; i++)
        {
            for(int j = i + 1; j <= B && l[j] - l[i] <= L3; j++)
            {
                if ( dp[i] + cost(l[j] - l[i]) < dp[j])
                    dp[j] = dp[i] + cost(l[j] - l[i]);

            }
        }
        cout << dp[B] << endl;
    }
}

long long cost(long long dis)
{
    if(dis <= L1) return C1;
    else if(dis <= L2) return C2;
    else return C3;
}
