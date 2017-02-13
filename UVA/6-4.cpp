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
    node(int x = -1, int y = -1, int d = 0):x(x),y(y),d(d){}
};

int solve(int x, int y);
int valid(int x, int y)
{
    if(x >= 0 && y >= 0 && x < 8 && y < 8) return 1;
    else return 0;
}

int dx[] = {1,  1, -1, -1,  2,  2, -2, -2};
int dy[] = {2, -2,  2, -2,  1, -1,  1, -1};
int map[8][8];
int x1, x2, y1, y2;
int main(void)
{
    
   
/*
    
*/  
    string co1;
    string co2;
    while(cin >> co1)
    {
        cin >> co2;
        //cout << co1 << " " << co2 << endl;
        x1 = co1[0] - 'a'; y1 = co1[1] - '1';
        x2 = co2[0] - 'a'; y2 = co2[1] - '1';
        //cout << x1 << " " << y1 << "," << x2 << " " << y2 << endl;
        int ans = solve(x1, y1);
        cout << "To get from " << co1 << " to " << co2 <<" takes "<< ans << " knight moves." <<endl;
        /*
        for(int i = 0; i < 8; i++)
        {
            for(int j = 0; j < 8; j++)
            {
                cout << map[i][j] << " ";
            }
            cout << endl;
        }
        
        cout << map[x2][y2] << endl;
        */
    }

}

int solve(int x, int y)
{
    memset(map, -1, sizeof(map));
    queue<node> q;
    q.push(node(x, y, 0));
    while(q.size())
    {
        //cout << "here" << endl;
        node t = q.front(); q.pop();
        map[t.x][t.y] = t.d;

        for(int i = 0; i < 8; i++)
        {
            int x = t.x + dx[i];
            int y = t.y + dy[i];
            //cout << x << " " << y << endl;
            if(valid(x, y) && map[x][y] == -1)
            {
                if(x == x2 && y == y2) return t.d + 1;
                //cout << x << " " << y << endl;
                q.push(node(x, y, t.d + 1));
            }
        }
    }
    return 0;
}