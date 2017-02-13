#include<cstdio>
#include<iostream>
#include<queue>
#include<string.h>
using namespace std;

struct node
{
    int x;
    int y;
    int d;
    int k;
    node(int x = -1, int y = -1, int d = 0, int k = 0):x(x),y(y),d(d),k(k){}
};

int valid(int x, int y);
void read();
int solve();

int dx[] = {1, -1,  0,  0};
int dy[] = {0,  0,  1, -1};
int map[20][20];
int delay[20][20];
int m, n;
int k;

int main(void)
{
    int T;
    cin >> T;
    while(T--)
    {
        read();
        int ans = solve();
        cout << ans << endl;
    }
}

int valid(int x, int y)
{
    if(x >= 0 && y >= 0 && x < m && y < n) return 1;
    else return 0;
}
void read()
{
    memset(map, -1, sizeof(map));
    memset(delay, -1, sizeof(delay));
    cin >> m >> n;
    cin >> k;
    int t;
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> t;
            map[i][j] = t;
        }
    }
}

int solve()
{
    
    queue<node> q;
    q.push(node(0, 0, 0, 0));
    delay[0][0] = 0;
    while(q.size())
    {
        node t = q.front(); q.pop();
        
        if(t.x == m - 1 && t.y == n - 1) return t.d;
        for(int i = 0; i < 4; i++)
        {
            int x = t.x + dx[i], y = t.y + dy[i];
            if(valid(x, y))
            {
                if(map[x][y] == 0 && delay[x][y] == -1)
                {
                    delay[x][y] = 0;
                    //cout << x << ", " << y << ", " << t.d + 1 << ", " << 0 << endl;
                    q.push(node(x, y, t.d + 1, 0));
                }
                if(map[x][y] == 1 && t.k < k && (delay[x][y] == -1 || t.k  + 1 < delay[x][y]))
                {
                    delay[x][y] = t.k + 1;
                    //cout << x << ", " << y << ", " << t.d + 1 << ", " << t.k + 1 << endl;
                    q.push(node(x, y, t.d + 1, t.k + 1));
                }
            }
        }
    }

    return -1;

}