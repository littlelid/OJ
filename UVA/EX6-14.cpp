#include<iostream>
#include<vector>
#include<queue>
#include<string.h>
#include<cstdio>
using namespace std;

const string dirs = "NESW";
const string turns = "FLR";
const int dr[] = {-1, 0, 1, 0};
const int dc[] = { 0, 1, 0,-1};

struct node
{
    int x, y, dir;
    node(int x=-1,int y=-1,int dir=-1):x(x),y(y),dir(dir){}
};

int dir2int(char ch);
int turn2int(char ch);
int read();
node walk(node t, int turn);
int valid(node t);
void solve();
void print(node u);

int maze[10][10][4][3];
int visit[10][10][4];
node p[10][10][4];
int start_x, start_y, end_x, end_y;
int dir;
int max_x;
int max_y;
string name;

int main(void)
{
    while(1)
    {
        cin >> name;
        if(name == "END") return 0;

        read();
        solve();

    }
}

int dir2int(char ch)
{
    return dirs.find(ch);
}
int turn2int(char ch)
{
    return turns.find(ch);
}

int read()
{
    memset(maze, 0, sizeof(maze));
    memset(visit, 0, sizeof(visit));
    memset(p, -1, sizeof(p));
    char ch;
    cin >> start_x >> start_y >> ch >> end_x >> end_y;
    dir = dir2int(ch);
    start_x += dr[dir];
    start_y += dc[dir];

    max_x = 0;
    max_y = 0;

    int x, y;
    while(1)
    {
        cin >> x;
        if(x == 0) break;
        cin >> y;

        if(x > max_x) max_x = x;
        if(y > max_y) max_y = y;

        string sign;
        while(1)
        {
            cin >> sign;
            if(sign == "*") break;
            int dir_temp = dir2int(sign[0]);
            for(int i = 1; i < sign.size(); i++)
            {
                maze[x][y][dir_temp][turn2int(sign[i])] = 1;

            }
        }
    }


    return 1;
}

node walk(node t, int turn)
{
    int dir = t.dir;
    if(turn == 1) dir = (dir + 3) % 4;
    if(turn == 2) dir = (dir + 1) % 4;
    return node(t.x + dr[dir], t.y + dc[dir], dir);
}

int valid(node u)
{
    if(u.x>=1 && u.x << max_x && u.y>=1 && u.y << max_y) return 1;
    else return 0;
}

void solve()
{
    queue<node> q;
    node n(start_x, start_y, dir);
    q.push(n);

    while(q.size())
    {
        node t = q.front(); q.pop();

        if(t.x == end_x && t.y == end_y) {print(t); return;}

        for(int i = 0; i < 3; i++)
        {

            node u = walk(t, i);

            if(maze[t.x][t.y][t.dir][i] && valid(u) && visit[u.x][u.y][u.dir] == 0)
            {

                visit[u.x][u.y][u.dir] = 1;
                p[u.x][u.y][u.dir] = t;

                q.push(u);

            }
        }
    }
    cout << name << endl;
    cout << "  No Solution Possible" << endl;
    return;

}

void print(node u)
{
    vector<node>  ans;
    while(1)
    {
        ans.push_back(u);
        if(u.x == start_x && u.y == start_y && u.dir == dir) break;
        u = p[u.x][u.y][u.dir];
    }
    ans.push_back(node(u.x - dr[u.dir], u.y - dc[u.dir], dir));
    cout << name << endl;
    int cnt = 0;
    for(int i = ans.size() - 1; i >= 0; i--)
    {
        if(cnt % 10 == 0) printf(" ");
        printf(" (%d,%d)",ans[i].x, ans[i].y);
        cnt++;
        if(cnt % 10 == 0) printf("\n");
    }
    if(ans.size() % 10 != 0) printf("\n");
}
