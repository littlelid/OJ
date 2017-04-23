#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;


int main(void)
{
    int n;
    while(scanf("%d", &n) == 1)
    {
        vector<int> v;
        for(int i = 100; i <= 999; i++)
        {
            int temp = i;
            int a3 = temp % 10;
            temp /= 10;
            int a2 = temp % 10;
            temp /= 10;
            int a1 = temp % 10;
            temp /= 10;
            if(a1+ a2 + a3 + a2 + a1 == n)
            {
                v.push_back(i * 100 + a2 * 10 + a1);
            }
            if(a1+ a2 + a3 + a3 +  a2 + a1 == n)
            {
                v.push_back(i * 1000 + a3 * 100  + a2 * 10 + a1);
            }

        }
        for(int i = 0; i < v.size(); i++)
        {
            if(v[i] < 100000) cout << v[i] << endl; 
        }
        for(int i = 0; i < v.size(); i++)
        {
            if(v[i] >= 100000) cout << v[i] << endl; 
        }
    }
}
