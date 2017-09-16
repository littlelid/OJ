#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int findIntegers(int num) {
        memset(d, -1, sizeof(d));
        
        vector<int> digits1;
        while(num)
        {
            digits1.push_back(num % 2);
            num /= 2;
        }
        for(int i = digits1.size() - 1; i >=0; i--)
        {
            digits.push_back(digits1[i]);
            cout << digits.back() << ' ';
        }
        cout << endl;
        return dfs(0, 0, 1);
    }

    int dfs(int idx, int lastdigit, int limit)
    {
        cout << idx << ' ' << lastdigit << ' ' << limit << endl;
        if(idx >= digits.size()) return 1;
        if(d[idx][lastdigit][limit] != -1) return d[idx][lastdigit][limit];

        int ans = 0;

        if(limit)
        {
            if(digits[idx] == 1)
            {
                ans += dfs(idx + 1, 0, 0);
                if(lastdigit == 0) ans += dfs(idx + 1, 1, 1);
            }
            else
            {
               ans += dfs(idx + 1, 0, 1); 
            }    
        }
        else
        {
            ans += dfs(idx + 1, 0, 0);
            if(lastdigit == 0) ans += dfs(idx + 1, 1, 0);
            
        }
        d[idx][lastdigit][limit] = ans;

        return ans;
    }
private:
    int d[32][2][2];
    vector<int> digits;
};

int main(void)
{
    Solution s;
    cout << s.findIntegers(1) << endl;
}