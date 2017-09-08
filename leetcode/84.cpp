#include<cstdio>
#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        
        heights.push_back(0);
        int ans = 0;
        stack<int> s;
        for(int i = 0; i <= heights.size(); i++)
        {
            
            if(s.empty() || heights[s.top()] <= heights[i])
            {
                s.push(i);
            }
            else
            {
                
                while(!s.empty() && heights[s.top()] > heights[i])
                {
                    int idx = s.top(); s.pop();
                    ans = max(ans, heights[idx] * (s.empty() ? i :(i - s.top() - 1) ) );
                    cout << idx << ' ' << i << endl;
                    cout << ans << endl;
                }
                s.push(i);
            }

        }
        return ans;
        cout << ans << endl;
    }
};

int main(void)
{
    Solution s;
    vector<int> heights;
    heights.push_back(4);
    heights.push_back(2);
    heights.push_back(0);
    heights.push_back(3);
    heights.push_back(2);
    heights.push_back(5);
    cout << s.largestRectangleArea(heights) << endl;;
}