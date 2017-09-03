#include<cstdio>
#include<iostream>
using namespace std;

class Solution {
public:
    int minSteps(int n) {
        num = n;
        
        for(int i = 0; i <= n + 5; i++) dp[i] = num;
        
        dfs(1, 0, 0);
            
        return dp[num];
    }
    
    void dfs(int i, int paste, int cost)
    {
        //cout << i << endl;
        dp[i] = min(dp[i], cost);
        
        if(i == num) return;
        
        
        if(i + paste <= num && dp[i + paste] > cost + 1) 
        {
            cout << "***" << endl;
            dfs(i + paste, paste, cost + 1);
        }
        if(2*i <= num && dp[i + i] > cost + 2)    
        {
            cout << "!!!" << endl;
            dfs(2*i, i, cost + 2);
        }
        
        
        return;
        
        
    }
    
private:
    int dp[1000000];
    int num;
};

int main(void)
{
    Solution s;
    cout << s.minSteps(10000) << endl;
}