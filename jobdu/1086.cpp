#include<cstdio>
#include<iostream>
#define INF 99999999999999
using namespace std;


long long  L1, L2, L3, C1, C2, C3;
long long get_cost(long long dis);
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
        long long temp;
        for(int i = 2; i <= N; i++)
        {
            cin >> temp;
            l[i] = temp;
        }

        long long dp[N + 5];
        dp[A] = 0;
        
        for(int i = A + 1; i <= B; i++) dp[i] = INF;
        for(int i = A; i <= B; i++ )
        {
            for(int j = i + 1; j <= B && l[j] - l[i] <= L3; j++)
            {
                long long cost = get_cost(l[j] - l[i]);
                if (cost + dp[i] < dp[j])
                    dp[j] = cost + dp[i];
            }
        }
       cout << dp[B] << endl; 


    }

}
long long get_cost(long long dis)
{
    if(dis <= L1) 
        return C1;
    else if(dis <= L2)
        return C2;
    else 
        return C3;
}
