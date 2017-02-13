#include<cstdio>
#include<iostream>
#include<string.h>
#include<vector>
using namespace std;

struct node
{
    int B;
    int T;
    node(int B, int T):B(B),T(T){}
};
typedef vector<node> v_n;
int visit[605];
int support[605];
int ans;
v_n map[605];
void dfs(int city, int dis);

int main(void)
{
    int N, M;
    while(1)
    {
        cin >> N;
        if(!N) break;
        //cout << "***********" << endl;
        memset(visit, 0, sizeof(visit));
        memset(support, 0, sizeof(support));
        for(int i = 0; i <= 604; i++)
        {
            map[i].clear();
        }
        ans = 1000000;
        cin >> M;
        int A, B, T;
        for(int i = 0; i < M; i++)
        {
            cin >> A >> B >> T;
            map[A].push_back(node(B,T));
            map[B].push_back(node(A,T));
        }
        
        int s;
        for(int i = 1; i <= N; i++)
        {
            cin >> s;
            support[i] = s; 
        }

        dfs(1, 0);

        if(ans == 1000000) cout << "-1" << endl;
        else               cout << ans << endl;
        
        
    }
}

void dfs(int city, int dis)
{
    if(dis > ans) return;
    //cout << "\tcity and dis: " << city  << "," << dis << endl;
    if(city == 2 && dis < ans)
    {
        ans = dis;
        return;
    }

    for(int i = 0; i < map[city].size(); i++)
    {
        int B = map[city][i].B;
        //cout << "\t\t" << B << endl;
        int T = map[city][i].T;
        if(!visit[B] && support[city] <= support[B])
        {
            visit[B] = 1;
            dfs(B, dis + T);
            visit[B] = 0;
        } 
    }
}