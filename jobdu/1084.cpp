#include<cstdio>
#include<iostream>

using namespace std;
int a[1000005];

int main(void)
{
    a[1] = 1;
    a[2] = 2;
    a[3] = 2;
    for(int i = 4; i <= 1000001; i++)
    {
        if(i % 2 == 1) a[i] = a[i - 1];
        else           a[i] = (a[i - 1] + a[i / 2]) % 1000000000;
    }
    int n;
    while(cin >> n)
    {
        cout << a[n] << endl;    
    }

}
