#include<cstdio>
#include<iostream>
#include<string>
#include<string.h>
#include<sstream>
using namespace std;
long long  power(int n);
int main(void)
{
    string n;
    while(cin >> n)
    {
        int len = n.size();
        int ans = 0;
        for(int i = 0; i  < len;  i++)
        {
            //cout << "\ti = " << i << endl;
            int k = len - 1 - i;
            for(int j = 0; j < n[i] - '0'; j++)
            {
                //cout << "\t\tj = " << j << endl; // i !!!!
                if(k) ans += 2 * k * power( k - 1);
                ans %= 20123;                

                if(j == 1 || j == 2)
                {
                    ans += power(k);
                    ans %= 20123; 
                }

            }
            if (n[i] == '1' || n[i] == '2')
            {
                for(int j = i + 1; j < len; j++)
                {
                    ans += (n[j] - '0') * power(len - 1 - j);
                    ans %= 20123;
                
                }
                ans += 1;
                ans %= 20123;
            
            }
        }
        cout << ans << endl; 
    
    }

}

long long   power(int n)
{
    if (n == 0) return 1;
    if (n == 1) return 10;
    if(n % 2 == 1)
        return power(n /2) * power(n /2) * 10 % 20123;
    else
        return power(n /2) * power(n /2) % 20123;
}
