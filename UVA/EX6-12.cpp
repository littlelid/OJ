#include<iostream>
#include<cstdio>
#include<string.h>
using namespace std;

char pic[105][105];
char flag[105][105];
int m, n;
int read();
int valid(int x, int y);
void dfs(int x, int y);

int main(void)
{
    while(read())
    {

        int num = 0;
        for(int i = 0; i < m; i++)
        {

            for(int j = 0; j < n; j++)
            {

                if(pic[i][j] == '@' && flag[i][j] == 0)
                {

                    num++;
                    dfs(i, j);
                }
            }
        }
        cout << num << endl;
    }
}


int read()
{
    memset(pic, 0, sizeof(pic));
    memset(flag, 0, sizeof(flag));

    scanf("%d%d", &m, &n);
    getchar();

    if(m == 0 && m == 0)  return 0;
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            pic[i][j] = getchar();
        }
        getchar();
    }

    return 1;
}
int  valid(int x, int y)
{
    if(flag[x][y] == 0 && x >= 0 && x < m && y >=0 && y < n ) return 1;
    else return 0;
}
void dfs(int x, int y)
{
    flag[x][y] = 1;
    if(pic[x][y] == '*') return;

    if(valid(x - 1, y))     dfs(x - 1, y);
    if(valid(x - 1, y - 1)) dfs(x - 1, y - 1);
    if(valid(x - 1, y + 1)) dfs(x - 1, y + 1);
    if(valid(x, y + 1))     dfs(x, y + 1);
    if(valid(x, y - 1))     dfs(x, y - 1);
    if(valid(x + 1, y))     dfs(x + 1, y);
    if(valid(x + 1, y - 1)) dfs(x + 1, y - 1);
    if(valid(x + 1, y + 1)) dfs(x + 1, y + 1);
}
