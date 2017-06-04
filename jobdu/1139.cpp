#include<cstdio>
#include<iostream>
#include<string.h>
using namespace std;


int mat[105][105];
int sum[105][105]; 
int main(void)
{
    int n;
    while(cin >> n)
    {
        memset(mat, 0, sizeof(mat));
        memset(sum, 0, sizeof(sum));
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                cin >> mat[i][j];
    
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + mat[i][j]; 
            }
        }
        
        int ans = -1 * (1 << 30);
        int tmp;
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
            {
               for(int k = i; k <= n; k++)
                {
                    for(int l = j; l <=n; l++)
                    {
                        tmp = sum[k][l] - sum[k][j - 1] - sum[i - 1][l] + sum[i - 1][j - 1];
                        if(tmp > ans) ans = tmp;
                    }
                
                }
            
            }
        }
        cout << ans << endl;
    }

}
