#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) 
    {
        this->nums = nums;
        this->target = target;
        dp[target] = 1;
        for(int i = 0; i < 100000; i++) 
        {
            dp[i] = -1;
        }
        dp[target] = 1;
        dfs(0);
        return dp[0];
    }

    int dfs(int cur) 
    {
        //cout << "cur:" << cur << endl;
        if(dp[cur] != -1) return dp[cur];
        int ans = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if(cur + nums[i] <= target) ans += dfs(cur + nums[i]);
            //if(!cur) cout << '\t' << ans << endl;
        }
        dp[cur] = ans;

        return ans;
    }

private:
    int dp[100000];
    int target;
    vector<int> nums;

};


int main(void)
{
    Solution s;
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    cout << s.combinationSum4(nums, 4) << endl;
}