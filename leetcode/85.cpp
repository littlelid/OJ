#include<cstdio>
#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Solution
{
public:
    int maximalRectangle(vector<vector<char> >& matrix) {
        if(matrix.empty()) return 0;
        int m = matrix.size();
        int n = matrix[0].size();
        int heights[n + 1];
        memset(heights, 0, sizeof(heights));
        
        int ans = 0;
        for(int i = 0; i < matrix.size(); i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(matrix[i][j] == '1') heights[j] += 1;
                else                    heights[j] = 0;
                //cout << heights[j] << ' ';
            }
            //cout << heights[n] << endl;
            stack<int> s;
            for(int j = 0; j <= n; j++)
            {
                if(s.empty() || heights[j] >= heights[s.top()])
                {
                    s.push(j);
                }
                else
                {
                    while(!s.empty() && heights[j] < heights[s.top()])
                    {
                        int idx = s.top(); s.pop();
                        //cout << j << ' ' << idx << endl;
                        ans = max(ans, heights[idx] * (s.empty() ? j : (j - s.top() - 1) ));

                    }
                    s.push(j);
                }
            }
        }
        return ans;

    }
};




int main(void)
{
    Solution s;
    vector<vector<char> > d;
    vector<char> d1;
    d1.push_back('0');d1.push_back('1');d1.push_back('1');
    vector<char> d2;
    d2.push_back('0');d2.push_back('1');d2.push_back('1');
    d.push_back(d1); d.push_back(d2);

    cout << s.maximalRectangle(d) << endl;
}