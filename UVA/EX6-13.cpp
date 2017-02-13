#include<cstdio>
#include<iostream>
#include<string.h>
#include<vector>
#include<algorithm>
using namespace std;

int pic[210][210];
int visit[210][210];
int map_1[210][210];
int H, W;

int  read();
int  valid(int x, int y);
void dfs_margin(int x, int y);
void gen_map(int x, int y);
void full_hole(int x, int y);
int main(void)
{
    int kase = 0;
    while(read())
    {
        vector<char>  ans;
        dfs_margin(0, 0);


        for(int i = 0; i <= H + 1; i++)
        {

            for(int j = 0; j <= 4 * W + 1; j++)
            {

                int num_hole = -1;
                if(pic[i][j]==1 && visit[i][j] == 0)
                {

                    num_hole = 0;
                    memset(map_1, 0, sizeof(map_1));

                    gen_map(i, j);

                    for(int k = 0; k <= H + 1; k++)
                    {

                        for(int l = 0; l <= 4 * W + 1; l++)
                        {

                            if(map_1[k][l] && pic[k][l] == 0)
                            {
                                num_hole++;
                                full_hole(k, l);
                            }
                        }
                    }
                }
                if(num_hole == 1) ans.push_back('A');
                if(num_hole == 3) ans.push_back('J');
                if(num_hole == 5) ans.push_back('D');
                if(num_hole == 4) ans.push_back('S');
                if(num_hole == 0) ans.push_back('W');
                if(num_hole == 2) ans.push_back('K');
            }

        }

        sort(ans.begin(), ans.end());
        int len = ans.size();
        kase++;
        cout << "Case " << kase << ": ";
        for(int i = 0; i < len; i++)
        {
            cout << ans[i];
        }
        cout << endl;
    }

}


int read()
{
    memset(visit, 0, sizeof(visit));
    memset(pic, 0, sizeof(pic));
    scanf("%d%d", &H, &W);
    if(H == 0 && W == 0) return 0;
    getchar();

    for(int i = 1; i <= H; i++)
    {
        for(int j = 1; j <= W; j++)
        {
            int ch = getchar();
            if(ch >= '0' && ch <= '9')
            {
                int n = ch - '0';
                pic[i][4 * (j-1) + 4] = n % 2;
                n /= 2;
                pic[i][4 * (j-1) + 3] = n % 2;
                n /= 2;
                pic[i][4 * (j-1) + 2] = n % 2;
                n /= 2;
                pic[i][4 * (j-1) + 1] = n % 2;
            }
            else
            {
                pic[i][4 * (j-1) + 1] = 1;
                if(ch == 'a') {pic[i][4 * (j-1) + 2] = 0; pic[i][4 * (j-1) + 3] = 1; pic[i][4 * (j-1) + 4] = 0;}
                if(ch == 'b') {pic[i][4 * (j-1) + 2] = 0; pic[i][4 * (j-1) + 3] = 1; pic[i][4 * (j-1) + 4] = 1;}
                if(ch == 'c') {pic[i][4 * (j-1) + 2] = 1; pic[i][4 * (j-1) + 3] = 0; pic[i][4 * (j-1) + 4] = 0;}
                if(ch == 'd') {pic[i][4 * (j-1) + 2] = 1; pic[i][4 * (j-1) + 3] = 0; pic[i][4 * (j-1) + 4] = 1;}
                if(ch == 'e') {pic[i][4 * (j-1) + 2] = 1; pic[i][4 * (j-1) + 3] = 1; pic[i][4 * (j-1) + 4] = 0;}
                if(ch == 'f') {pic[i][4 * (j-1) + 2] = 1; pic[i][4 * (j-1) + 3] = 1; pic[i][4 * (j-1) + 4] = 1;}
            }
        }
        getchar();
    }

    return 1;
}
int  valid(int x, int y)
{
    if(x>=0 && x <= H + 1 && y >= 0 && y <= 4 * W + 1) return 1;
    else return 0;
}

void dfs_margin(int x, int y)
{
    if(pic[x][y]) return;

    pic[x][y] = 2;
    if(valid(x - 1, y)) dfs_margin(x - 1, y);
    if(valid(x + 1, y)) dfs_margin(x + 1, y);
    if(valid(x, y - 1)) dfs_margin(x, y - 1);
    if(valid(x, y + 1)) dfs_margin(x, y + 1);
}

void gen_map(int x, int y)
{
    if(pic[x][y] == 2 || map_1[x][y] == 1) return;

    visit[x][y] = 1;
    map_1[x][y] = 1;

    if(valid(x - 1, y)) gen_map(x - 1, y);
    if(valid(x + 1, y)) gen_map(x + 1, y);
    if(valid(x, y - 1)) gen_map(x, y - 1);
    if(valid(x, y + 1)) gen_map(x, y + 1);
}

void full_hole(int x, int y)
{
    if(pic[x][y] != 0) return;

    pic[x][y] = 3;
    if(valid(x - 1, y)) full_hole(x - 1, y);
    if(valid(x + 1, y)) full_hole(x + 1, y);
    if(valid(x, y - 1)) full_hole(x, y - 1);
    if(valid(x, y + 1)) full_hole(x, y + 1);
}
