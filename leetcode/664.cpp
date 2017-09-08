#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    int strangePrinter(string s) {
        if(s.size() == 0) return 0;
        
        for(int i = 0; i < s.size(); i++)
        {
            vector<int> d1;
            for(int j = 0; j < s.size(); j++)
            {
                if(i == j) d1.push_back(1);
                else       d1.push_back(-1);
            }
            d.push_back(d1);
        }
        this->s = s;
        return dfs(0, s.size() - 1);

    }

    int dfs(int i, int j)
    {
        //cout << "dfs:" << i << ' ' << j << endl; 
        if(d[i][j] != -1) return d[i][j];
        
        int ans = 1 << 30;
        if(s[i] == s[i + 1]) 
        {
            
            //cout << "*1* " << s[i] << ' ' << s[i + 1] << endl;
            ans = min(ans, dfs(i + 1, j));

        }
        else
        {
            //cout << "*2*" << endl;
            ans = min(ans, 1 + dfs(i + 1, j));
        
            for(int m = i + 2; m <= j; m++)  // s[i] != s[i + 1]
            {
                if(s[m] == s[i]) 
                    ans = min(ans, dfs(i + 1, m - 1) + dfs(m, j));
            }
        }

        d[i][j] = ans;
        return ans;
    }

private:
    string s;
    vector<vector<int> > d;

};



int main(void)
{
    Solution s;
    //cout << s.strangePrinter("aaabbb") << endl;
    cout << s.strangePrinter("aaa") << endl;
    
}