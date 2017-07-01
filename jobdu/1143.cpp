#include<cstdio>
#include<iostream>
#include<string>

using namespace std;

int main(void)
{
    string a, b;
    while(1)
    {
        cin >> a >> b;
        if(a == "0" && b == "0") break;
        
        int l = a.size() < b.size() ? a.size() : b.size();
        int c = 0;
        int ans = 0;
        int tmp = 0;
        for(int i = 1; i <= l; i++)
        {
            tmp = a[a.size() - i] - '0' + b[b.size() - i] - '0' + c;
            if (tmp>= 10)
            {
                ans += 1;
                c = 1;
            }
            else
                c = 0;
        }
        if(ans == 1)
            cout << "1 carry operation." << endl;
        else if(ans >= 2)
            cout << ans << " carry operations." << endl;
        else
            cout << "NO carry operation." << endl;
    }
}

