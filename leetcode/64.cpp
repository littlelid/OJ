#include<cstdio>
#include<iostream>
#include<vector>
#include<string.h>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int> > grid) {
        /*
        for(int i = 0; i < grid.size(); i++)
        {
            vector<>
        }
        */
        m = grid.size();
        if(m == 0) return 0;
        n = grid[0].size();
        
        this->grid = grid;
        
        memset(dp, -1, sizeof(dp));
        dp[m - 1][n - 1] = grid[m - 1][n - 1];
        
        dfs(0, 0);
        /*
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                cout << dp[i][j] << ' ';
            }
            cout << endl;
        }
        */
        return dp[0][0];
    }
    
    int dfs(int i, int j)
    {
        //cout << i << ' ' << j << endl;
        if(dp[i][j] != -1) return dp[i][j];
        int ans = 1 << 30;
        //cout << "*1*" << endl;
        if( i + 1 < m) ans = min(ans, grid[i][j] + dfs(i + 1, j));
        //cout << "*2*" << endl;
        if( j + 1 < n) ans = min(ans, grid[i][j] + dfs(i, j + 1));
        //cout << "*3*" << endl;
        
        dp[i][j] = ans;
        
        return ans;
    }
private:
    int dp[100][100];
    vector<vector<int> > grid;
    int m;
    int n;
};

int main(void)
{
    Solution s;
    vector<vector<int> > grid;
    vector<int> d1;
    d1.push_back(1);
    d1.push_back(2);
    vector<int> d2;
    d2.push_back(3);
    d2.push_back(4);
    grid.push_back(d1);
    grid.push_back(d2);

    cout << s.minPathSum(grid) << endl;
}