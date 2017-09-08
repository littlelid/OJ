#include<cstdio>
#include<iostream>
#include<vector>
#include<string.h>
using namespace std;

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int size = nums.size();
        //nums.push_front(1);
        this->nums.push_back(1);
        for(int i = 0; i < nums.size(); i++)
            this->nums.push_back(nums[i]);
        this->nums.push_back(1);
        //cout << nums.size() << endl;
        //cout << nums[5] << endl;
        memset(t, -1, sizeof(t));
        return dfs(1, size, 0, size  + 1);
    }

    int dfs(int i, int j, int left, int right)
    {
        if(left >= right) return 0;
        if(i > j) return 0;
        if(t[left][right] != -1) return t[left][right];

        int ans = -1;
        for(int k = i; k <= j; k++)
        {
            int t1 =  nums[left] * nums[k] * nums[right];
            int t2 =  dfs(i, k - 1, left, k);
            int t3 =  dfs(k + 1, j, k, right);
            
            /*
            if(left == 0 && right == 5)
            {
                cout << '\t' << k << endl;
                if(t1 + t2 + t3 > ans)
                {
                    cout << '\t' << nums[left]  << ' ' <<  nums[k] << ' ' <<  nums[right] << ' ' << right << endl;
                    cout << '\t' << t1 << ' ' <<t2 << ' ' << t3 << " " << (t1 + t2 + t3) << "   ||   "  << k << ' ' << right << endl;
                    
                }

            }
            */
            ans = max(ans,  t1 + t2 + t3);

        }
        t[left][right] = ans;
        //cout << i << ' ' << j << " " << left << ' ' << right  << ": " << ans << endl;
        return ans;
    }

private:
    int t[500][500];
    vector<int> nums;
};

int main(void)
{

    Solution s;
    vector<int> nums;
    nums.push_back(3);
    nums.push_back(1);
    nums.push_back(5);
    nums.push_back(8);
    cout << s.maxCoins(nums) << endl;

}