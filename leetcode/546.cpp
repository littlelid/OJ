#include<cstdio>
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int removeBoxes(vector<int>& boxes) {
        this->boxes = boxes;
        for(int i = 0; i < 105; i++)
            for(int j = 0; j < 105; j++)
                for(int k = 0; k < 105; k++)
                {
                    t[i][j][k] = -1;
                    if(j < i) t[i][j][k] = 0;
                    if(j == i) t[i][j][k] = (k + 1) * (k + 1);
                }
        int ans = dfs(0, boxes.size() - 1, 0);
        //cout << ans << endl;
        return ans;
    }

    int dfs(int i, int j, int k)
    {
        //cout << i << ' ' << j << ' ' << k << endl;
        if(t[i][j][k] != -1) return t[i][j][k];

        int ans = -1;
        ans = max(ans, (k + 1) * (k + 1) + dfs(i + 1, j, 0) );
        for(int m = i + 1; m <= j; m++)
        {
            if(boxes[m] == boxes[i])
            {
                ans = max(ans, dfs(i + 1, m - 1, 0) + dfs(m, j, k + 1));
            }
        }
        t[i][j][k] = ans;
        //cout << '\t' << ans << endl;
        return ans;
    }

private: 
    int t[105][105][105];
    vector<int> boxes;
};

int main(void)
{
    Solution s;
    vector<int> boxes;
    // [1,3,2,2,2,3,4,3,1]
    boxes.push_back(1);    
    boxes.push_back(3);    
    boxes.push_back(2);    
    boxes.push_back(2);    
    boxes.push_back(2);    
    boxes.push_back(3);    
    boxes.push_back(4);    
    boxes.push_back(2);    
    boxes.push_back(1);
    cout << s.removeBoxes(boxes) << endl;     
}