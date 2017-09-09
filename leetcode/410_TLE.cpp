#include<cstdio>
#include<iostream>
#include<vector>
#include<map>
using namespace std;


class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        if(nums.size() == 0) return 0;

        int sum = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            sums[i] = sum;
        }
        int max_ = -1<<30;
        for(int i = nums.size() - 1; i >= 0; i--)
        {
            max_ = max(max_, nums[i]);
            maxs[i] = max;
        }

    }

    int dfs(int i, int m, int left_sum)
    {
        
        if(d[i][m].count(left_sum)) retrun d[i][m][left_sum];


        int ans = 1 << 30;
        if(m == 1) {
            ans = sums[nums.size() - 1] - sums[i] + nums[i];
            ans += left_sum;
            d[i][m][left_sum] = ans;
            return ans;            
        }
        else if(nums.size() - i == m )
        {
            int max_ = left_sum + nums[i];
            ans = max(max_, maxs[i+1]);
        }
        else
        {
            if(nums.size() - i >= m)
                ans = min(ans, max(left_sum + nums[i], dfs(i + 1, m - 1, 0) ) );

            if(nums.size() - i >= m + 1)
                ans = min(ans, dfs(i + 1, m, left_sum + nums[i]));
        }
        d[i][m][left_sum] = ans;
        return ans;
    }
private:
    map<int,int> d[1005][50];
    vector<int> nums;
    int sums[1005];
    int maxs[1005];
};


int main(void)
{

}