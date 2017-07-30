#include<cstdio>
#include<iostream>
#include<string.h>
using namespace std;

int F, V;
int dp[105][105];
int v[105][105];
int dfs(int i, int j);
int main(void)
{
    while(cin >> F >> V)       
    {
        //cout << sizeof(dp) << endl; 
        for(int i = 1; i <= F; i++)
            for(int j = 1; j <= V; j++)
                cin >> v[i][j],dp[i][j] = -100;


        /*
        int max_ = -100;
        for(int i = V; i >= 1; i--)
        {
            if(max_ < v[F][i]) max_ = v[F][i];
            dp[F][i] = max_;
        }
        max_ = -100;
        for(int i = F; i >= 1; i--)
        {
            if(max_ < v[i][V]) max_ = v[i][V];
            dp[i][V] = max_;
        }
        for(int i = 1; i <= F; i++)
        {
            for(int j = 1; j <= V; j++)
                cout << dp[i][j] << ' '; 
            cout << endl;
        }
        */
        dfs(1, 1);
        cout << dp[1][1] << endl;
    
    }
    
    
}

int dfs(int i, int j)
{
    if(dp[i][j] != -100) {return dp[i][j]; }

    int max_sum = -100000;
    int temp;
    for(int k = j; k <= V && V - k >= F -i ; k++)
    {
        if(k + 1 <= V && i + 1 <= F)
            temp = v[i][k] + dfs(i + 1, k + 1);
        else
            temp = v[i][k];
        if (temp > max_sum) max_sum = temp;
    }
    dp[i][j] = max_sum;

    return max_sum;

}
