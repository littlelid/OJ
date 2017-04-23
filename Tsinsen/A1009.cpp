#include<cstdio>
#include<iostream>

using namespace std;

int main(void)
{
    int n;
    int max = -1000000;
    int max_sec = -1000000;
    int min = 10000000;
    int min_sec = 1000000;
    int num;
    int sum  = 0;
    int temp;
    cin >> n;
    while(n--)
    {
        cin >> num;
        if(num > max_sec) { max_sec = num;}
        if(max_sec > max) 
        {
            temp = max;
            max = max_sec;
            max_sec = temp;
        }
        if(num < min_sec) min_sec = num;
        if(min_sec < min) 
        {
            temp = min;
            min = min_sec;
            min_sec = temp;
        }
        sum += num * num;
        //cout << max_sec << ' ' << min_sec << endl;
    }
    cout << max_sec << endl;
    cout << min_sec << endl;
    cout << sum << endl;
}
