#include<cstdio>
#include<iostream>
#include<vector>
#include<string.h>
#include<string>
using namespace std;

int q[100 + 5];
int lr_max[100 + 5];
int rl_max[100 + 5];
int main(void)
{
    int n;
    while(cin >> n)
    {
        for(int i = 1; i <= n; i++) lr_max[i] = 1;
        for(int i = 1; i <= n; i++) rl_max[i] = 1;
        //memset(lr_max, 0, sizeof(lr_max)* 105); 
        //memset(rl_max, 0, sizeof(rl_max)* 105); 
        for(int i = 1; i <= n; i++)
            cin >> q[i];
         
        for(int i = n; i >=1; i--)
        {
            for(int j = i; j <=n; j++)
                if(q[j] < q[i] && 1 + lr_max[j] > lr_max[i])
                        lr_max[i] = 1 + lr_max[j];
        }
        for(int i = 1; i <= n; i++)
            for(int j = i; j >= 1; j--)
                if(q[j] < q[i] && 1 + rl_max[j] > rl_max[i])
                        rl_max[i] = 1 + rl_max[j];

        int ans = -1;
        for(int i = 1; i <= n; i++)
        {
            if (lr_max[i] + rl_max[i] > ans) ans = lr_max[i] + rl_max[i];
        }
        ans -= 1;
        cout << n - ans << endl;

    }

}
