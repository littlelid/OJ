#include<cstdio>
#include<iostream>
#include<vector>
#include<string.h>
using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        sum = 0;
        for(int i = 0; i < nums.size(); i++)
            sum += nums[i];
        
        if(sum % 2 != 0) return false;

        sum /= 2;
        
        memset(visit, 0, sizeof(visit));
        memset(cnt, 0, sizeof(cnt));
        for(int i = 0; i < nums.size(); i++)
            cnt[nums[i]] += 1;

        for(int i = 0; i < 105; i++)
            if(cnt[i]) this->nums.push_back(i);
        dfs(0);
        if(visit[sum]) return true;
        else           return false;
            
    }

    void dfs(int i)
    {
        //cout << "visit:" << i << endl;
        //for(int i = 0; i < nums.size(); i++)
        //    cout << "\t" << nums[i] << ": " << cnt[nums[i]] << endl;;
    
        if(i > sum) return;
        //if(can) return;
        if(visit[i]) return;
        
        visit[i] = 1;
        for(int j = 0; j < nums.size(); j++)
        {
            if(cnt[nums[j]] > 0) 
            {
                cnt[nums[j]] -= 1;
                //cout << "\t" << "using " << nums[j]  << ", to visit: " << i + nums[j] << endl;
                dfs(i + nums[j]);
                cnt[nums[j]] += 1;
            }
        }

        return;
    }
private:
    int visit[20010];
    int cnt[105];
    int sum;
    
    vector<int> nums;
};

int main(void)
{
    Solution s;
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(5);
    nums.push_back(11);
    nums.push_back(5);
    cout << s.canPartition(nums) << endl;
}