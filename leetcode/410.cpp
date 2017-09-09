#include<cstdio>
#include<iostream>
#include<vector>

using namespace std;

class Solution
{
public:
    int splitArray(vector<int>& nums, int m) {
        long long sum = 0; 
        int max_num = -1;
        for(int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            max_num = max(max_num, nums[i]);
        }
    
        long long l = max_num;
        long long r = sum;
        long long ans = sum;
        while(l <= r)
        {
            long long mid = (l + r) / 2;

            int parts = cut(mid, nums, m);
            
            cout << l << ' ' << r << ' ' << mid << ' ' << parts << endl;
            if(parts <= m) 
            {
                ans = min(ans, mid);
                r = mid - 1;   
            }
            else l = mid + 1;

            cout << l << ' ' << r << endl;
        }
        //ans = min(ans, )
        return ans;

    
    }

    int cut(long long target, vector<int>& nums, int m)
    {
        int cnt = 0;
        long long sum = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];

            if(sum > target)
            {
                sum = nums[i];
                cnt++;
                
                //if(cnt > m) return true;
                

            }
        }
        cnt++;
        return cnt;
    }
};

int main(void)
{
    Solution s;
    vector<int > nums;
    nums.push_back(7);
    nums.push_back(2);
    nums.push_back(5);
    nums.push_back(10);
    nums.push_back(8);
    cout << s.splitArray(nums, 5) << endl;
}