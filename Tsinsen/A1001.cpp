#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;

int main(void)
{
    for(int i = 0; i < 64; i++)
    {
        int v[6];
        int cnt = 0;
        for(int j = 0; j < 6; j++)
        {
            int temp = i & (1 << (5 - j));
            if(temp!= 0)
            {
                v[j] = 1;
                cnt++;
            }
            else
            {
                v[j] = 0;
            }
        }
       if(cnt % 2)
       {
            for(int j = 0; j < 6; j++) cout << v[j];
            cout << endl;
       }
    }

}
