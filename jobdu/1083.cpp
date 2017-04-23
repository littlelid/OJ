#include<cstdio>
#include<iostream>
#include<string.h>
using namespace std;

int main(void)
{
    string a, b;
    while(cin >> a)
    {
        long long ans = 0;
        cin >> b;
        for(int i = 0; i < a.size(); i++)
        {
            for(int j = 0; j < b.size(); j++)
            {
                ans += (a[i] - '0') * (b[j] - '0');
            }
        }
        cout << ans << endl;

    }


}
