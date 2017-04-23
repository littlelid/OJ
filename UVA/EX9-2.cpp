#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;

int n;
int boxs[35][3];
int d[35][3];
int vis[35][3];
int dp(int idx, int k);
int main(void)
{
    int kase = 0;
    while(1)
    {
        cin >> n;
        if(n == 0) break;
        memset(boxs, 0, sizeof(boxs));
        memset(d, 0, sizeof(d));
        memset(vis, 0, sizeof(vis));
        for(int i = 0; i < n; i++)
        {
            int box[3];
            cin >> box[0] >> box[1] >> box[2];
            sort(box, box + 3);
            boxs[i][0] = box[0];
            boxs[i][1] = box[1];
            boxs[i][2] = box[2];
        }
        
        int max_h = -1;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < 3; j++)
            {
                int temp = dp(i, j);
                if (max_h < temp)
                    max_h = temp;
            }
        }
        kase++;
        cout << "Case " << kase <<": maximum height = " << max_h << endl;
    }

}

int dp(int idx, int k)
{
    if(vis[idx][k] == 1)
        return d[idx][k];
    vis[idx][k] = 1;

    int a, b;
    if(k == 0)      {a = boxs[idx][1]; b = boxs[idx][2]; }
    else if(k == 1) {a = boxs[idx][0]; b = boxs[idx][2]; }
    else            {a = boxs[idx][0]; b = boxs[idx][1]; }

    int find = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            int c, f;
            if(j == 0)      {c = boxs[i][1]; f = boxs[i][2]; }
            else if(j == 1) {c = boxs[i][0]; f = boxs[i][2]; }
            else            {c = boxs[i][0]; f = boxs[i][1]; }
                           
            if(c < a && f < b )
            {
                find = 1;           
                int v = boxs[idx][k] + dp(i, j);
                if(v > d[idx][k])
                {
                    d[idx][k] = v;
                }
            }
        
        }

    
    }
    if(!find) d[idx][k] = boxs[idx][k];
    return d[idx][k];

}
