#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        int n1 = nums1.size(), n2 = nums2.size();
        vector<int> ans;

        for(int k1 = max(k - n2, 0); k1 <= min(n1, k); k1++)
        {
            ans = max(ans, maxNumber(maxNumber(nums1, k1), maxNumer(nums2, k - k1) ));
        }
        
        return ans;
    }

    vector<int> maxNumber(vector<int> nums, int k)
    {
        vector<int> out;
        int drop = nums.size() - k;

        for(int i = 0; i < nums.size(); i++)
        {
            while(drop && out.size() && out.back() < nums[i])
            {
                out.pop_back();
                drop--;
            }
            out.push_back(nums[i]);
        }

        out.resize(k);
        return out;
    }

    vector<int> maxNumber(vector<int> nums1, vector<int> nums2)
    {
        vector<int> out;

        while(nums1.size() + nums2.size())
        {
            vector<int> now = nums1 > nums2 ? nums1 : nums2;
            out.push_back(now[0]);
            out.erase(out.begin());
        }
        return out;
    }
};

int main(void)
{
    vector<int> v1, v2;
    v1.push_back(-1);
    //v1.push_back(4);
    v2.push_back(-2);
    v2.push_back(3);
    vector<int> ans;
    ans = max(v1, v2);
    for(int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << endl;
    }
}
