#include<cstdio>
#include<iostream>
#include<string>
#include<vector>
using namespace std;

int divide(string s, int k);
int main(void)
{
    string s;
    while(1)
    {
        cin >> s;
        if(s == "-1") break;
        vector<int> ans;
        for(int k = 2; k <= 9; k++)
        {
           if(divide(s, k)) ans.push_back(k);
        }

        if(ans.size() == 0) cout << "none" << endl;
        else
        {
            for(int i = 0; i < ans.size(); i++)
            {
                if(!i) cout << ans[i];
                else cout << ' ' << ans[i];
            }
            cout << endl;
        }
        
    }
}

int divide(string s, int k)
{
    int c = 0;
    int num = 0;
    for(int i = 0; i < s.size(); i++)
    {
        num = c * 10 + (s[i] - '0');
        if(num >= k)
        {
            num %= k;    
        }
        c = num;
    }
    if(c == 0) return 1;
    else return 0;

}
