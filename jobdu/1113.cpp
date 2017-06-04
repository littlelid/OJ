#include<cstdio>
#include<iostream>
using namespace std;

long long  get_level(long long x);
long long  get_down(long long m, long long  l, long long  factor);
int main(void)
{
    long long  m, n;
    while(1)
    {
        cin >> m >> n;
        if (m == 0 && n == 0)
            break;

        long long level_m = get_level(m);
        long long level_n = get_level(n);
        long long down_left = get_down(m, level_n - level_m, 0);
        long long down_right = get_down(m, level_n - level_m, 1);
    
        long long ans = 1;
        ans = ( 1 << (level_n - level_m + 1) ) - 1;
        //cout << "1:" << ans << endl;        
        //cout << "2:" << down_left << ' ' << down_right << endl;
        if (n < down_left)
            ans -= (down_right - down_left + 1) ;
        else if(n < down_right)
            ans -= (down_right - n);

        cout << ans << endl;
    }
}

long long  get_level(long long x)
{
    long long  l = 0;
    while(x)
    {
        l += 1;
        x /= 2;
    }
    return l;
}
long long  get_down(long long m, long long l, long long factor)
{
    while(l--)
    {
        m *= 2; 
        m += factor;
    }
    return m;
}
