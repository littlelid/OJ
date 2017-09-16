#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int numTrees(int n) {
        vector<int> ans;
        ans.push_back(1);

        int temp;
        for(int i = 1; i <=n; i++)
        {
            temp = 0;
            for(int j = 0; j <= i - 1; j++)
            {
                temp += ans[j] * ans[ i - 1 - j];
                //cout << temp << endl;
            }
            ans.push_back(temp);
            //cout << temp << ' ';
        }
        //cout << endl;

        return ans[n];
    }
};
   
int main(void)
{
    Solution s;
    cout << s.numTrees(5) << endl;
}