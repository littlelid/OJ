#include<cstdio>
#include<iostream>
#include<iostream>
#include<map>
using namespace std;


class Solution
{
public:
    bool isMatch(string s, string p) 
    {
        int i = 0; 
        int j = 0;
        int match = 0;
        int star_idx = -1;

        while(i < s.size())
        {
            //cout << i << ' ' << j << endl;
            if(j < p.size() && (s[i] == p[j] || p[j] == '?') )
            {
                i++; j++;
                continue;
            }
            else if(j < p.size() && p[j] == '*')
            {
                //cout << "*2*" << endl;
                star_idx = j;
                j++;
                match = i;
                continue;
            }
            else if(star_idx != -1)
            {
                j = star_idx + 1;
                match++;
                i = match;
                continue;
            }
            
            return false;
        }
        //cout << "*1*" << endl;
        while(j < p.size() && p[j] == '*') j++;
        
        return j == p.size();
    }
};


int main(void)
{
    Solution s;
    cout << s.isMatch("aab", "a*a?") << endl;
}