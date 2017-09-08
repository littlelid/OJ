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
        int i = 0, j = 0;
        stack<int> star_idx;
        stack<int> match;
        //starch<char> star_char;
        //int match;
        while(i < s.size())
        {
            //if(i >= s.size()) star_idx.pop();

            //cout << i << ' ' << j << endl;
            //cout << 
            if(j < p.size() && (s[i] == p[j] || p[j] == '.' ) &&(j + 1 >= p.size() || p[j + 1] != '*'))
            {
                i++;
                j++;
                //cout << "\t*1*" << endl;
                continue;
            }
            
            if(j + 1 < p.size() && p[j + 1] == '*')
            {
                star_idx.push(j);
                
                j += 2;

                match.push(i);
                //cout << "\t*2*" << endl;
                continue;
            }
            
            if(star_idx.size() > 0)
            {
                //cout << s[]
                while(s[match.top()] != p[star_idx.top()] && p[star_idx.top()] != '.') 
                {
                    //cout << "\tpop: " << star_idx.top() << ' ' << match.top() <<  endl;
                    star_idx.pop();
                    match.pop();
                    
                    if(star_idx.size() == 0) return false;
                }
                
                //cout << '\t' << i << ' ' << star_idx.top() << ' ' <<  match.top()  << endl;
                //cout << "\t" << s[i]  << ' ' << p[star_idx.top()] << endl; 
                //match++;
                i = match.top();
                i++;

                match.pop(); match.push(i);

                j = star_idx.top() + 2;
                //cout << "\t*3*: " << i << ' ' << j <<endl;
                continue;
            } 
            //cout << "\t*4*" << endl; 
            


            return false;
            
        }
        while(j + 1 < p.size() && p[j+1] == '*') j += 2;
        return j == p.size();
        
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