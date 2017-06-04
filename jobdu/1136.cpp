#include<cstdio>
#include<iostream>
using namespace std;

int main(void)
{
    int n;
    while(cin >> n)
    {
        int x, y;
        while(n--)
        {
            cin >> x >> y;
            if(x == y || x - y == 2)
            {
                int ans;
                if(x % 2 == 0)
                    ans = x * 2;
                else
                    ans = x * 2 - 1;
                ans -= (x - y);
                cout << ans << endl;
            }
            else
            {
                cout << "No Number" << endl;
            
            }
        }
    
    }

}
