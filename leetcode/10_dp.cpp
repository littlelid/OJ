#include<cstdio>
#include<iostream>
#include<iostream>
#include<stack>

using namespace std;

class Solution
{
public:
    bool isMatch(string s, string p) 
    {
        //int s, p;
        if(s.size() == 0 || p.size() == 0) 
            return true;
        
        int match = false;
        int i = 0;
        int j = 0;
        while(i < s.size() && j < p.size() &&  (s[i] == p[j] || p[j] == '.') )
        {
            i++; j++;
        }

        if(i == s.size())
        {
            while(j + 1 < p.size() && p[j + 1] == '*') j += 2;

            return j == p.size();
        }
        if(j == p.size()) return false;

        if(p[j] == '*')
        {
            while(i < s.size())
            {
                
            }
        }
        
        

    }
};

int main(void)
{
    Solution s;
    /*
    cout << s.isMatch("ccccb", "c*a*b") << endl;
    cout << s.isMatch("aa", "a") << endl;
    cout << s.isMatch("aa", "aa") << endl;
    cout << s.isMatch("aaa", "aa") << endl;
    cout << s.isMatch("aa", "a*") << endl;
    cout << s.isMatch("aa", ".*") << endl;
    cout << s.isMatch("ab", ".*") << endl;
    cout << s.isMatch("aab", "c*a*b") << endl;

    cout << s.isMatch("aaba", "ab*a*c*a") << endl;
    */
    cout << s.isMatch("a", "ab*") << endl;
}