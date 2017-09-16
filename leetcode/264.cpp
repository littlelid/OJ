#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;


class Solution {
public:
    int nthUglyNumber(int n) {
        if(n == 0) return 0;
        if(n == 1) return 1;
        
        int i = 0, j = 0, k = 0;
        vector<int> ans(n);

        ans[0] = 1;
        for(int m = 1; m < n; m++)
        {
            ans[m] = min(ans[i]*2, min(ans[j]*3, ans[k]*5));

            if(ans[m] == ans[i] * 2) i++;
            if(ans[m] == ans[j] * 3) j++;
            if(ans[m] == ans[k] * 5) k++;
        }
        return ans[n-1];
    }


};

int main(void)
{
    Solution s;
    cout << s.nthUglyNumber(100) << endl;
}