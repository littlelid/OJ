#include<cstdio>
#include<iostream>
#include<string.h>
using namespace std;

int m, n;
int dfs(int m, int n, int limit);
int main(void)
{
    int t;
    while(cin >> t)
    {
        while(t--)
        {
            cin >> m >> n;
            //if (n > m) n = m;  
            cout << dfs(m, n, 0) << endl;
        }
    }
}

int dfs(int m, int n, int limit)
{        
    
    if(m == 0) return 1;

    if(n == 1) return 1;
    if(n == 2) return m / 2 + 1 - limit > 0 ? m / 2 + 1 - limit : 0;
     
    int sum = 0;
    for(int i = limit; i <= m / 2; i++) 
    {
        int temp = dfs(m - i, n - 1, i);
        sum += temp;
        //cout << i << ' ' << m - i << ' ' << n - 1 << ' ' << temp << endl;
    }
    return sum;
}
