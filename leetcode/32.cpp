#include<cstdio>
#include<iostream>
#include<stack>
#include<string>
#include<map>
#include<vector>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<char> char_st;
        stack<int>  idx_st;
        
        if(s.size() == 0) return 0;
        char_st.push(s[0]);
        idx_st.push(0);
        idx_parter.push_back(-1);
        for(int i = 1; i < s.size(); i++)
        {
            if(s[i] == ')')
            {
                if(char_st.size() > 0 && char_st.top() == '(') 
                {
                    char_st.pop();
                    idx_parter.push_back(idx_st.top());
                    idx_st.pop();
                }
                else
                {
                    char_st.push(')');
                    idx_st.push(i);
                    idx_parter.push_back(-1);
                }
            }
            else
            {
                char_st.push('(');
                idx_st.push(i);
                idx_parter.push_back(-1);
            }
        }
        //cout << "***" << endl;
        for(int i = idx_parter.size() - 1; i >= 0; i--)
        {
            //cout << i << endl;
            getlink(i);
        }

        
        
        
        int ans = 0;
        for(int i = 0; i < idx_parter.size(); i++)
        {
            //cout << idx_parter[i] << ' ';
            if(idx_parter[i] != -1)
            {
                ans = max(ans, i - idx_parter[i] + 1);
            }
        }
        //cout << endl;
        return ans;
    }
    //-1 -1 1 -1 3 -1 5
    int getlink(int i)
    {
        //if(i < 0) return 
       // cout << i << endl;
        int j = idx_parter[i];
        
        if(j == -1) 
        {
            return i;
        }

        int res;
        if(j == 0 || idx_parter[j - 1] == -1) 
        {
            res = j;
        }
        else
        {

            res = getlink(j - 1);

        }

        idx_parter[i] = res;
        return res;
    }
private:
    vector<int> idx_parter;
};

int main(void)
{
    Solution s;
    cout << s.longestValidParentheses("(()())()(") << endl;
    
}