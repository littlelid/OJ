#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

const int MAX = 99999;
int map[105][105];
int q[105][105][4];
int d_x[] = {0,  0, 1, -1};
int d_y[] = {1, -1, 0,  0};

int max_q(int x, int y);
struct node_{
    int x;
    int y;
    int h;
    node_(int x, int y, int h):x(x),y(y),h(h){}

    bool operator < (const node_& o) const
    {
        return h < o.h;
    }
};
int main(void)
{
    int R, C;
    int h;
    while(cin >> R >> C)
    {
        vector<node_> nodes;
        for(int i = 0; i <= R + 1; i++)       
        {
            for(int j = 0; j <= C + 1; j++)
            {
                if( i>= 1 && i <= R && j >= 1 && j <= C)
                {
                    cin >> h;
                    map[i][j] = h;
                    nodes.push_back(node_(i, j, h));
                    q[i][j][0] = q[i][j][1] = q[i][j][2] = q[i][j][3] = 0;
                }
                else
                {
                    map[i][j] = MAX;
                }
            }
        }
        sort(nodes.begin(), nodes.end());
        int x, y;
        for(int i = 0; i < nodes.size(); i++)
        {
            x = nodes[i].x;   
            y = nodes[i].y;   
            h = nodes[i].h;
            
            int flag = 0;
            for(int j = 0; j < 4; j++)
            {
                if(map[x][y] > map[x + d_x[j]] [ y +d_y[j] ])
                {
                    q[x][y][j] =  max_q(x + d_x[j], y + d_y[j]) + 1;
                    //cout << x << ' ' << y <<  ' ' << q[x][y][j] << endl;
                }
            }
        }
        int ans = -1;
        for(int i = 1; i <= R; i++)
            for(int j = 1; j <= C; j++)
                for(int k = 0; k <= 3; k++)
                    ans = max(ans, q[i][j][k]);
        cout << ans  + 1<< endl;
    
    }
}
int max_q(int x, int y)
{
   int max_ = 0;
   for(int i = 0; i < 4; i++)
        max_ = max(max_, q[x][y][i]);

   return max_;

}
