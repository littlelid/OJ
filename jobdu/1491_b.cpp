#include<cstdio>
#include<iostream>
#include<string>
#include<string.h>
#include<sstream>
using namespace std;
int power(int n);
string Int_to_String(int n);
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
        stringstream ss;
        ss << n;
        int num;
        ss >> num;
        int t_ans = 0;
        for(int i = 1; i <= num; i++ )
        {
            string tmp = Int_to_String(i);
            for(int j = 0; j < tmp.size(); j++)
            {
               if(tmp[j] == '1' || tmp[j] == '2') t_ans += 1;
        
            }
        }
        cout << ans << endl; 
        cout << t_ans % 20123 << endl; 
    
    }

}
string Int_to_String(int n)
{
    ostringstream stream;
    stream<<n;  //n为int类型
    return stream.str();
}

int power(int n)
{
    if(n == 0) return 1;

    if(n % 2 == 0) 
    {
        int temp = power(n / 2) % 20123;
        return (temp * temp) % 20123;
    }    
    else
    {
        int temp = power((n - 1) / 2 ) % 20123;
        return (temp * temp * 10) % 20123;
    }
}
