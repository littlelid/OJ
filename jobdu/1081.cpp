#include<cstdio>
#include<iostream>
using namespace std;

int main(void)
{
    int a0, a1, p, q, k;
    while(cin >> a0)
    {
        cin >> a1 >> p >> q >> k;
        int a2;
        for(int i = 2; i <= k; i++)
        {
            a2 = p * a1 + q * a0;
            a0 = a1 % 10000;
            a1 = a2 % 10000;
        }
        if(k == 1)      cout << a1 % 10000 << endl;
        else if(k == 0) cout << a0 % 10000 << endl;
        else            cout << a2 % 10000 << endl;
    }
}

