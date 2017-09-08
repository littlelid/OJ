#include<cstdio>
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> ans;
        ans.push_back(0);
        if(num == 0) return ans;
        ans.push_back(1);
        if(num == 1) return ans;
        
        for(int i = 1; i < 32; i++)
        {
            int temp = 1 << i;
            for(int j = 0; j < temp; j++)
            {
                ans.push_back(1 + ans[j]);
                if (ans.size() >= num + 1) break;
            }
            if (ans.size() >= num + 1) break;
        }
        
        for(int i = 0; i < ans.size(); i++)
            cout << ans[i] << ' ';
        cout << endl;
        return ans;
    }
};
int main(void)
{
    Solution s;
    s.countBits(0);

}