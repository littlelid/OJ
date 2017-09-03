#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        vector<int> dp;
        
        for(int i = 0; i < A.size(); i++)
            dp.push_back(i - 1);
        
        for(int i = 2; i < A.size(); i++)
        {
            if(A[i] - A[i - 1] == A[i - 1] - A[i - 2])
            {
                dp[i] = dp[i - 1];
            }
        }
        int ans = 0;
        for(int i = 0; i < A.size(); i++)
        {
            for(int j = i + 2; j < A.size(); j++)
            {
                if(dp[j] <= i) ans += 1;
                else          break;
            }
        }
        return ans;
     }
};

int main(void)
{
    Solution s;
    vector<int> A;
    A.push_back(1);
    A.push_back(2);
    A.push_back(3);
    A.push_back(4);
    A.push_back(5);
    cout << s.numberOfArithmeticSlices(A) << endl;
}