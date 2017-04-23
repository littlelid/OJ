#include<cstdio>
#include<iostream>

using namespace std;

long long func(long long n);
int main(void)
{
    long long  n;
    while(cin >> n)
        cout << func(n) << endl;


}
long long func(long long n)
{
    if(n == 1) return 1;

    return n * func(n - 1);

}
