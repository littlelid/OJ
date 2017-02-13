#include<cstdio>
#include<iostream>
#include<vector>
#include<string.h>
using namespace std;

int digits[10];
int valid(int n);
int check();
int main(void)
{
    int n;
    int first = 1;

    while(1)
    {
        cin >> n; 
        if(n == 0) break;
        
        if(first) first = 0;
        else      cout << endl;
        vector<int > ans;
        
        for(int i = 0; i < 50000; i++)
        {
            memset(digits, 0, sizeof(digits));
            
            if(valid(i) && valid(i * n) && check()) ans.push_back(i);
        }
        if(ans.size() == 0) cout << "There are no solutions for " <<  n << "." << endl;
        else{
            for(int i = 0; i < ans.size(); i++)
            {
                printf("%05d", ans[i]*n);
                printf(" / ");
                printf("%05d", ans[i]);
                printf(" = %d\n", n);
            }
        }
        
    }
}

int valid(int n)
{
    if(n >= 100000) return 0;
    if(n < 1000) return 0;
    if(n < 10000) digits[0] = 1;
    int temp;
    while(n)
    {
        temp = n % 10;
        //cout << temp << " ";
        if(digits[temp]) return 0;
        digits[temp] = 1;
        n /= 10;
        
    }
    return 1;
}

int check()
{
    int sum = 0;
    for(int i = 0; i <= 9; i++) sum += digits[i];

    if(sum == 10) return 1;
    else          return 0;
}
/*
        memset(digits, 0, sizeof(digits));
        for(int i = 0; i <= 4; i++)
        {
            digits[i] = 1;
            num = i;
            cout << i << endl;
            for(int j = 0; j <= 9; j++)
            {
                //cout << "\t" << j << endl;
                if(digits[j]) continue;
                digits[j] = 1;
                
                num *= 10;
                num += j;
                //cout << "\t" << j << endl;
                for(int k = 0; k <= 9; k++)
                {
                    //cout << "\t\t" << k << endl;
                    if(digits[k]) continue;
                    digits[k] = 1;

                    num *= 10;
                    num += k;
                    //cout << "\t\t" << k << endl;
                    for(int l = 0; l <= 9; l++)
                    {
                        if(digits[l]) continue;
                        digits[l] = 1;
                        
                        num *= 10;
                        num += l;
                        //cout << "\t\t\t" << l << endl;
                        for(int m = 0; m <= 9; m++)
                        {
                            if(digits[m]) continue;
                            digits[m] = 1;
                            
                            num *= 10;
                            num += m;
                            //cout << "\t\t\t\t" << m << endl;
                            cout << num << endl;
                            if(valid(num * n)) ans.push_back(num);
                            digits[m] = 0;

                            num *= 10;
                            num += m;
                        }
                        digits[l] = 0;
                    }
                    digits[k] = 0;
                }
                digits[j] = 0;
            }
            digits[i] = 0;
        }
        cout << ans.size() << endl;
        */