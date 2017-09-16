#include<cstdio>
#include<iostream>
#include<string>
#include<stack>
#include<utility>
#include<vector>
using namespace std;

class Solution {
public:
    int numDistinct(string s, string t) {
        if(s.size() == 0) return 0;
        else if(t.size() == 0) return 1;
        this->s = s;
        this->t = t;
        //memset(d, -1, sizeof(d));
        for(int i = 0; i < s.size(); i++)
        {
            vector<int> d1;
            for(int j = 0; j < t.size(); j++)
            {
                d1.push_back(-1);
            }
            d.push_back(d1);
        }
        return  dfs(0, 0);

        
    }

    int dfs(int i, int j)
    {
        cout << i << ' ' << j << endl;
        if(j >= t.size()) return 1;
        if(i >= s.size()) return 0;
        if(d[i][j] != -1)
            return d[i][j];
        int ans = 0;
        for(int k = i; k < s.size(); k++)
        {
            if(s[k] == t[j])
                ans += dfs(k + 1, j + 1);
        }
        
        d[i][j] = ans;
        return ans;
        
    }
private:
    vector< vector<int> > d; 
    string s, t;
};

int main(void)
{
   Solution s;
    cout << s.numDistinct("ccc", "c") << endl;
}