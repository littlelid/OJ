#include<cstdio>
#include<iostream>
#include<string.h>
#include<queue>
#include<string>
using namespace std;

int dx[] = {-2, -1, 1 ,2, 2, 1, -1, -2};
int dy[] = {-1, -2, -2, -1, 1, 2, 2, 1};
struct node{
    int x;
    int y;
    int cnt;
    node(int x, int y, int cnt):x(x),y(y),cnt(cnt){}
};
int valid(int x);
int abs_(int x);
void find_dis(int d[][9], int i, int j);
int dis[9][9][9][9];
int main(void)
{
    memset(dis, -1, sizeof(dis));
    for(int i = 1; i <= 8; i++)
    {
        for(int j = 1; j <= 8; j++)
        {
            find_dis(dis[i][j], i, j);
        }
    
    }
    /*
    for(int i = 1; i <= 8; i++)
    {
        for(int j = 1; j <= 8; j++) 
        {
            cout << dis[1][3][i][j] << ' ';
        }
        cout << endl;
    }
    cout << '*' <<  endl;
    for(int i = 1; i <= 8; i++)
    {
        for(int j = 1; j <= 8; j++) 
        {
            cout << dis[1][8][i][j] << ' ';
        }
        cout << endl;
    }
    cout << '*' <<  endl;
    for(int i = 1; i <= 8; i++)
    {
        for(int j = 1; j <= 8; j++) 
        {
            cout << dis[8][1][i][j] << ' ';
        }
        cout << endl;
    }
    cout << '*' << endl;
    for(int i = 1; i <= 8; i++)
    {
        for(int j = 1; j <= 8; j++) 
        {
            cout << dis[8][8][i][j] << ' ';
        }
        cout << endl;
    }
    cout << '*' << endl;
    */

    string s;
    while(cin >> s)
    {
        int map[9][9];
        memset(map, 0, sizeof(map));
        int x_king, y_king; 
        for(int i = 0; i < s.size(); i+=2)
        {
            if(!i)
            {
                x_king = s[i] - 'A' + 1;
                y_king = s[i+1] - '0';
            }
            else
            {
                map[s[i]-'A' + 1][s[i+1] - '0'] += 1;
                //cout << s[i]-'A' + 1 << ' ' << s[i+1] - '0' << endl;
            }
        }
    /*
    for(int i = 1; i <= 8; i++)
    {
        for(int j = 1; j <= 8; j++) 
        {
            cout << map[i][j] << ' ';
        }
        cout << endl;
    }
    cout << endl;
    */
        int sum_cnt[9][9];
        memset(sum_cnt, 0, sizeof(sum_cnt));

        int ans = 1 << 20;
        int temp;
        for(int i = 1; i <= 8; i++)
            for(int j = 1; j <= 8; j++) // end
            {
                for(int k = 1; k <= 8; k++)
                    for(int l = 1; l <= 8; l++) // start & knight
                    {
                        if(map[k][l])
                        {
                            
                            sum_cnt[i][j] += map[k][l] * dis[k][l][i][j];
                        }
                    }

                temp = sum_cnt[i][j] + abs_(i - x_king) + abs_(j - y_king);            
                if(ans >= temp)
                { 
                    ans = temp; 
                    //cout << i << ' ' << j << ' ' << ans << endl;
                }
            }
       /* 
        for(int i = 1; i <= 8; i++)
        {
            for(int j = 1; j <= 8; j++) 
            {
                cout << sum_cnt[i][j] << ' ';
            }
            cout << endl;
        }

        cout << ans << endl;
        */
        for(int i = 1; i <= 8; i++)
        {
            for(int j = 1; j <= 8; j++) // start
            {
                for(int k = 1; k <= 8; k++)    
                {
                    for(int l = 1; l <= 8; l++) // end
                    {
                        for(int m = 1; m <= 8; m++)
                        {
                            for(int n = 1; n <= 8; n++) // knight
                            {
                                if(map[m][n])
                                {
                                    temp = 0;
                                    temp += sum_cnt[k][l];
                                    temp -= dis[m][n][k][l];
                                    temp += dis[m][n][i][j] + dis[i][j][k][l];
                                    temp += abs_(i - x_king) + abs_(j - y_king);

                                    if(ans >temp) 
                                    {   
                                        ans = temp;
                                        //cout << temp <<  " (" << k << ',' << l << "), " <<  "pass: (" << i << ',' << j << ") " <<  "use: (" << m << ',' << n << ") "<< endl;
                                    }
                                }
                            }
                        }
                    
                    }
                }
            }
        }
        cout << ans << endl;

    }
}

void find_dis(int d[][9], int i, int j)
{
    queue<node> q;
    
    q.push(node(i, j, 0));
    int x, y, cnt;
    while(!q.empty())
    {
        node t = q.front(); q.pop();
        x = t.x;
        y = t.y;
        cnt = t.cnt;
        //cout << x << ' ' << y << ' ' << cnt << endl;       
        d[x][y] = cnt;
        for(int k = 0; k < 8; k++)
        {
            //cout << dx[k] << ' ' << dy[k] << endl;
            //cout << x + dx[k] << ' ' << y + dy[k]  << endl;
            if(valid(x + dx[k]) && valid(y + dy[k]) && d[x+dx[k]][y+dy[k]] == -1)
            {
                //cout << "*" << endl;
                q.push(node(x+dx[k], y+dy[k], cnt+1));
            }
        }
    }
}

int valid(int x)
{
    //cout << x << endl;
    if(x >= 1 && x <= 8) return 1;
    else return 0;
}
int abs_(int x)
{
    return x >= 0 ? x : -x;
}
