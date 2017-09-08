#include<cstdio>
#include<iostream>
#include<string>
#include<string.h>
#include<vector>
using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        s = word1;
        p = word2;
        

        for(int i = 0; i <= s.size(); i++)
        {
            vector<int> d1;
            for(int j = 0; j <= p.size(); j++)
            {
                if(i == s.size()) d1.push_back(p.size() - j );
                else if(j == p.size()) d1.push_back(s.size() - i);
                else d1.push_back(-1);
                
            }
            d.push_back(d1);
        }
        return dfs(0, 0);
    }

    int dfs(int i, int j)
    {
        if(d[i][j] != -1) return d[i][j];
      
        int ans = 1 << 30;
        if(s[i] == p[j]) ans = min(ans, dfs(i + 1, j + 1));
        else
        {
            ans = min(ans, 1 + dfs(i + 1, j + 1) );
            //if(i == 0 && j == 0) cout << ans << endl;
            ans = min(ans, 1 + dfs(i, j + 1) );
            //if(i == 0 && j == 0) cout << ans;
            ans = min(ans, 1 + dfs(i + 1, j) );
            //if(i == 0 && j == 0) cout << ans;
        }

        d[i][j] = ans;
        return ans;

    }

private:
    string s;
    string p;
    vector<vector<int> > d;
};

int main(void)
{
    Solution s;
    //cout << s.minDistance("axt", "xt") << endl;
    //cout << s.minDistance("axt", "xxt") << endl;
    cout << s.minDistance("aat", "xt") << endl;

}