#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        vector<int> dp;        
   
        dp.push_back(1);
        int max_len = 1;
        for(int i = 1; i < nums.size(); i++)
        {
            dp.push_back(1);
            for(int j = 0; j < i; j++)
            {
                if(nums[j] < nums[i]) 
                {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            if(dp[i] > max_len) max_len = dp[i];
            //cout << i << ' ' << dp[i] << endl;
        }
       
        return max_len;
        

    }
};

int main(void)
{
    Solution s;
    vector<int> x;
    x.push_back(10);
    x.push_back(9);
    x.push_back(2);
    x.push_back(5);
    x.push_back(3);
    x.push_back(7);
    x.push_back(101);
    x.push_back(18);
    cout << s.lengthOfLIS(x) << endl;

}