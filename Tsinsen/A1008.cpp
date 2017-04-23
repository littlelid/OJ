#include<cstdio>
#include<iostream>

using namespace std;

int main(void)
{
    int n;
    int max = -1000000;
    int min = 10000000;
    int num;
    int sum  = 0;
    cin >> n;
    while(n--)
    {
        cin >> num;
        if(num > max) max = num;
        if(num < min) min = num;
        sum += num;
    }
    cout << max << endl;
    cout << min << endl;
    cout << sum << endl;
}
