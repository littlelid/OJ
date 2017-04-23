#include<cstdio>
#include<iostream>
#include<string.h>
#include<algorithm>
#define INF 9999999
using namespace std;
int map[15][200];
int next_row[15][200];
int dp[15][200];
int main(void)
{
    int m, n;
    while(cin >> m >> n)
    {
        int first;
        int min_path = INF;
        memset(map, 0, sizeof(map));
        memset(next_row, 0, sizeof(next_row));
        memset(dp, INF, sizeof(dp));
        
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                int temp;
                cin >> temp;
                map[i][j] = temp;    
            }
        }
        //cout << dp[0][0] << endl; 
        for(int j = n - 1; j >= 0; j--)
        {
            for(int i = 0; i < m; i++)
            {
                if(j == n - 1)
                {
                   dp[i][j] = map[i][j];
                }
                else
                {
                    int row[3] = {i, i - 1, i + 1};
                    if(row[1] == -1) row[1] = m - 1;
                    if(row[2] == m) row[2] = 0;
                    sort(row, row + 3);

                    for(int k = 0; k < 3; k++)
                    {
                        //cout << map[i][j] << endl;
                        int v = map[i][j] + dp[row[k]][j + 1];
                        //cout << "V: " << v << " dp[" << i << "][" << j  << "]" <<": " << dp[i][j] << endl;
                        if(dp[i][j] > v) 
                        {
                            //cout << " change!" << endl;
                            dp[i][j] = v;
                            next_row[i][j] = row[k];
                        }
                    }
                }
                if(j == 0 && dp[i][j] < min_path) 
                {
                    min_path = dp[i][j]; 
                    first    = i;
                }
            }
        }

        cout << first + 1;
        for(int j = 0; j < n - 1; j++)
        {
            cout << " " << next_row[first][j] + 1;
            first = next_row[first][j];
        }
        cout << endl << min_path << endl; 
    }
}
