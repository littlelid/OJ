#include<cstdio>
#include<iostream>
#include<string>
#include<vector>
#include<string.h>
using namespace std;

const int LENGTH_BIN = 4000;
const int LENGTH_INT = 1010;

int bin[LENGTH_BIN];
int ans[LENGTH_INT];
int add_factor[LENGTH_INT];
int num[LENGTH_INT];

int is_zero(int *num)
{
    for(int i = 0; i < LENGTH_INT; i++)
        if(num[i] != 0) return 0;

    return 1;
}

void divide_2(int* num)
{
    for(int i = LENGTH_INT - 1; i >= 0; i--)
    {
        if(i) num[i- 1] += num[i] % 2 * 10;
        num[i] /= 2;
    }
}

int mod_2(int *num)
{
    return num[0] % 2;
}

void add(int* num1, int* num2)
{
    int c = 0;
    for(int i = 0; i < LENGTH_INT; i++)
    {
        int temp = num1[i] + num2[i] + c;    
        num1[i] = temp % 10;
        c  = temp / 10;
    }
}

void  mult_2(int *num)
{
    int c = 0;
    for(int i = 0; i < LENGTH_INT; i++)
    {
        int temp = num[i] * 2 ;
        num[i] = (temp + c) % 10;
        c =  (temp / 10);
    }
}

void print(int* num)
{
    int k = LENGTH_INT;
    while(num[k] == 0 && k >= 0) k--;
    for(int i = k; i >=0; i--)
        cout << num[i];
    if (k < 0) cout << "0";
    cout << endl;
}
int main(void)
{
    string num_t;
    while(cin >> num_t)
    {
        memset(ans, 0, sizeof(ans));
        memset(add_factor, 0, sizeof(add_factor));
        memset(num, 0, sizeof(num));

        for(int i = 0; i < num_t.size(); i++)
            num[num_t.size() - i - 1] = num_t[i] - '0';
        //print(num);

        int bin_idx = 0;
        do{
            bin[bin_idx++] = mod_2(num);
            divide_2(num);
            //t_print(num); 
        }while(!is_zero(num));
        //cout << "IDX: " << bin_idx << endl; 
        //cout << "bin: ";
        //t_print(num_b);
        add_factor[0] = 1;
        for(int i = 0; i < bin_idx; i++)
        {
            if(bin[bin_idx - i - 1 ])
            {
                add(ans, add_factor);
                //cout << "factor: ";
                //print(add_factor);
                //cout << "ans: ";
                //print(ans);
            }
            mult_2(add_factor);
        }
        //cout << "ans:";
        print(ans);    
   }
    
}
