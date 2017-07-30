#include<cstdio>
#include<iostream>
using namespace std;

int dfs(int i, int j);
int triangle[105][105];
int dp[105][105];
int N;
int main(void)
{
    for(int i = 0; i <= 104; i++)
        for(int j = 0; j <= 104; j++)
            triangle[i][j] = -1;

    while(cin >> N)
    {
        for(int i = 0; i <= 104; i++)
            for(int j = 0; j <= 104; j++)
                dp[i][j] = -1;
        for(int i = 1; i <= N; i++)
        {
            for(int j = 1; j<= i; j++)
            {
                cin >> triangle[i][j];
            }
        }
        int ans = dfs(1, 1);
        /*
        for(int i = 1; i <= N; i++)
        {
            for(int j = 1; j <= i; j++)
                cout <<  dp[i][j] << ' ';
            cout << endl;
        }
        */
        cout << ans << endl;
    
    }

}

int dfs(int i, int j)
{
    //cout << i  << ' ' << j << endl;
    if(dp[i][j] != -1) return dp[i][j];
    
    int try0 = triangle[i][j];
    int try1 = triangle[i][j];
    if(i + 1  <= N)
    {
        try0 += dfs(i+1, j);
        if(j <= i)
        {
            try1 += dfs(i+1, j+1);
        }
    }
    //cout << try0 << ' ' << try1 << endl;
    int ans = try0 > try1 ? try0 : try1;
    dp[i][j] = ans;
    return ans;
}
