#include<cstdio>
#include<iostream>
#include<string.h>
using namespace std;

int ans[25];
int solve(int cur);
int main(void)
{
    memset(ans, -1, sizeof(ans));
    ans[1] = 1;
    ans[2] = 2;
    solve(20);
    //for(int i = 0; i <= 20; i++)
       // cout << ans[i] << ' ';
    //cout << endl;
    int n;
    while(cin >> n)
    {
        cout << ans[n] << endl;
    }
}

int solve(int cur)
{
    //if(cur == 1) return 1;
    if(ans[cur] != -1) return ans[cur];

    int a = 0;
    int b = 0;
    if(cur - 1 > 0) a = solve(cur - 1);
    
    if(cur - 2 > 0) b = solve(cur - 2);
    //cout << cur << ' '  << a << ' '  << b << endl;
    ans[cur] = a + b;
    return a + b;
}
