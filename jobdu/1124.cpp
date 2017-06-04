#include<cstdio>
#include<iostream>
#include<string>
using namespace std;

int main(void)
{
    string s;
    while(1)
    {
        cin >> s;
        if(s == "0") break;
        long long  ans = 0;
        for(int i = 0; i < s.size(); i++)
            ans += (s[i] - '0'); 

        while(ans >= 10) 
        {
            long long temp = 0;
            while(ans)
            {
                temp += ans % 10;
                ans /= 10;
            }
            ans = temp;
        }
        cout << ans << endl;
    }
}
