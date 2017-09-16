#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        int LIMIT = 1000000007;
        
        int l1 = 1;
        int l2 = factor(s.substr(0, 1));
        if(s.size() == 1) return l2;
        int temp;
        cout << l1 << ' ' << l2 << endl;
        for(int i = 1; i < s.size(); i++)
        {
            
            temp = l1 * factor(s.substr(i - 1, 2)) + l2 * factor(s.substr(i, 1));
            l1 = l2;
            l2 = temp % LIMIT;
        }

        return l2;

    }

    int factor(string s)
    {
        if(s.size() == 1)
        {
            if(s == "*")
                return 9;
            else if(s == "0")
                return 0;
            else return 1;
        }
        else if(s.size() == 2)
        {
            if(s[0] == '*')
            {
                if(s[1] == '*') return 15;
                else if(s[1] <= '6' && s[1] >= '0') return 2;
                else return 1;
            }
            else if(s[0] == '1' || s[0] == '2')
            {
                if(s[1] == '*') return s[0] == '1' ? 9 : 6;
                else 
                {
                    if( 10*(s[0] - '0') + (s[1] - '0') <= 26) return 1;
                    else return 0;
                }
            }
            else 
                return 0;
            
            
        }
        return 0;
    }
};

int main(void)
{
    Solution s;
    string t;// = "10*0";
    cin >> t;
    cout << t. size() << endl;
    //t.resize(50000);
    cout << s.numDecodings(t) << endl;
}
