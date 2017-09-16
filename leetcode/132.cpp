#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;

class Solution
{
public:
    int minCut(string s) 
    {
        this->s = s;
        for(int i = 0; i < s.size(); i++)
        {
            vector<int> d1;
            for(int j = 0; j < s.size(); j++)
            {
                if(i >= j) d1.push_back(0);
                else       d1.push_back(-1);
            }
            d.push_back(d1);
        }
        for(int i = 0; i < s.size(); i++)
        {
            for(int len = 0; i - len >= 0 && i + len < s.size(); len ++)
            {
                if(s[i - len] == s[i + len]) d[i - len][i + len] = 0;
                else break;
            }
            
        }
        
        for(int i = 0; i < s.size(); i++)
        {
            for(int len = 0; i - len >= 0 && i + 1 + len < s.size(); len ++)
            {
                if(s[i - len] == s[i + 1 +len]) d[i - len][i + 1+ len] = 0;
                else break;
            }
            
        } 
        for(int i = 0; i < s.size(); i++)
        {
            for(int j = 0; j < s.size(); j++) 
            {
                printf("%2d ", d[i][j]);    
            }
            cout << endl;
        }
        return dfs(0, s.size() - 1);
    }

    int dfs(int i, int j)
    {
        cout << i << ' ' << j << endl;
        if(i >= j) return 0;
        if(d[i][j] != -1) return d[i][j];
        
        int ans = j - i;
        for(int m = i; m <= j; m++)
        {
            if(d[i][m] != -1)
            {
                //cout << i << ' ' << m << endl;
                int temp = dfs(i + 1, m - 1) + dfs(m + 1, j) + 1 * (m < j);
                //if(i == 0 && j == s.size() - 1 && ans > temp) cout << "\t" << m << ' ' << temp << endl;
                //ans = min(ans, dfs(i + 1, m - 1) + dfs(m + 1, j) + 1 * (m < j));
                ans = min(ans, temp);
                
            }
        }
        d[i][j] = ans;
        return ans;
    }
   
private:
    vector<vector<int> > d;
    string s;

};

int main(void)
{
    Solution s;

    //cout << s.minCut("abcbabbabb") << endl;
    //cout << s.minCut("aabaabaabbaa") << endl;
    //cout << s.minCut("aababbaa") << endl;
    //cout << s.minCut("ababba") << endl;
    cout << s.minCut("aaabbaaaa") << endl;
    //cout << s.minCut("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa") << endl;
}