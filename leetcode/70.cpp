#include<cstdio>
#include<iostream>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        vector<int> d0(n + 1, -1);
        d = d0;
        d[0] = 0;
        
        return dfs(n);
    }
    int dfs(int n)
    {
        if(d[n] != -1) return d[n];

        int ans = 0;
        if(n - 1 >= 0) ans += dfs(n - 1);
        if(n - 2 >= 0) ans += dfs(n - 2);

        d[n] = ans;
        return ans;

    }

private:
    vector<int> d;
};

int main(void)
{
    
}
