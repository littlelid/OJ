#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        LIMIT= 1;
        for(int i = 1; i <= 9; i++) LIMIT *= 10;
        LIMIT += 7;
        cout << LIMIT << endl;
        len = s.size();
        this->s = s;
        for(int i = 0; i < s.size(); i++)
        {
            d.push_back((long long)-1);
        }
        if(s.back() == '*') d[len - 1] = (long long)9;
        else                d[len - 1] = (long long)1;
        d.push_back((long long)1);
        return (int)dfs(0);
        
    }

    long long dfs(int cur)
    {
        cout << cur << endl;
        if(s[cur] == '0') return 0;
        if(d[cur] != -1) return d[cur];
        
        int ch1 = s[cur], ch2 = s[cur + 1];
        
        long long ans = 0;
        if(ch2 == '0')
        {
            if(ch1 == '*')
                ans += mymod( 2 * dfs(cur + 2) );
            else if(ch1 == '2' || ch1 == '1')
                ans = dfs(cur + 2);
            else
                ans = 0;
        }
        else if(ch1 != '*')
        {
            ans += dfs(cur + 1);
            if(ch2 != '*')
            {
                if( 10*(ch1 - '0') +(ch2 - '0') <= 26 )
                {
                    ans += dfs(cur + 2);
                }
            }
            else
            {
                if(ch1 == '1') ans += mymod(9 * dfs(cur + 2) );
                if(ch1 == '2') ans += mymod(6 * dfs(cur + 2) );
            }
        }
        else
        {
            ans += mymod(9 *  dfs(cur + 1)  );
            if(ch2 != '*')
            {
                if(ch2 <= '6' && ch2 >= '0') ans += mymod(2 * dfs(cur + 2) );
                else                         ans += dfs(cur + 2) ;
            }
            else
            {
                ans += mymod(15 * dfs(cur + 2) );
            }
        }
        ans = mymod(ans); 
        d[cur] = ans;
        return ans;
    }

    long long mymod(long long num)
    {
        return num % LIMIT;
    }
private:
    vector<long long> d;
    string s;
    int len;
    long long LIMIT;
};

int main(void)
{
    Solution s;
    string t;
    cin >> t;
    t.resize(50000);
    cout << s.numDecodings(t) << endl;
}
