#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int calculateMinimumHP(vector<vector<int> >& dungeon) {
        map = dungeon;
        h = dungeon.size();
        w = dungeon[0].size(); 

        for(int i = 0; i < h; i++)
        {
            vector<int> d;
            for(int j = 0; j < w; j++)
                d.push_back(-1);
            dp.push_back(d);
        }
        if(map[h - 1][w - 1] >= 0) dp[h-1][w-1] = 1;
        else                       dp[h-1][w-1] = 1 - map[h-1][w-1];

        dfs(0, 0);
        for(int i = 0; i < h; i++)
        {
            for(int j = 0; j < w; j++)
                cout << dp[i][j] << ' ';
            cout << endl;
        }
        return dp[0][0];
    }
    int dfs(int i, int j)
    {
        if(dp[i][j] != -1) return dp[i][j];

        int ans = 1<<30;
        if(i + 1 < h) ans = min(ans, dfs(i + 1, j));
        if(j + 1 < w) ans = min(ans, dfs(i, j + 1)) ;
        
        if(map[i][j] >= ans) ans = 1;
        else ans = ans - map[i][j];

        dp[i][j] = ans;

        return ans;
    }

private:
    vector<vector<int> > map;
    vector<vector<int> > dp;
    int h,w;
};

int main(void)
{
    int x[] = {-2, -3, 3, -5, -10, 1, 10, 30, -5};
    int h = 3;
    int w = 3;
    vector<vector<int> > map;
    for(int i = 0; i < h; i++)
    {
        vector<int> d;
        for(int j = 0; j < w; j++)
            d.push_back(x[i*w + j]);
        map.push_back(d);
    }
    cout << "***" << endl;
    Solution s;
    s.calculateMinimumHP(map);
}
