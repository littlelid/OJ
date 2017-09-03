#include<cstdio>
#include<iostream>
using namespace std;


class Solution {
public:
    int uniquePaths(int m, int n) {
        h = m;
        l = n;
        for(int i = 1; i <= 102; i++)
        {
            for(int j = 1; j <= 102; j++)
                d[i][j] = -1;
        }
        d[h][l] = 1;
        cout << h << ' ' << l << endl;
        //cout << dfs(1, 1) << endl; 
        return dfs(1, 1);
    }
    int dfs(int i, int j)
    {
        cout << "dfs:" <<  i << ' ' << j << endl;
        if(d[i][j] != -1) return d[i][j];
        
        int ans = 0;
        if(valid(i, j + 1)) 
        {   
            ans += dfs(i, j + 1);
        }
        if(valid(i + 1, j)) 
        {
            ans += dfs(i + 1, j);
        }

        d[i][j] = ans;
        
        return ans;
    }
    
    int valid(int m, int n)
    {
        if(m <= h && n <= l) {cout << "***" << endl; return 1;}
        else                {cout << "!!!" << endl; return 0;}
    }

private:
    int h;
    int l;
    int d[105][105];
};

int main(void)
{
    Solution s;
    cout << s.uniquePaths(, 2) << endl;
}