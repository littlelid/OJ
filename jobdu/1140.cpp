#include<cstdio>
#include<iostream>
#include<string>
#include<vector>
#include<string.h>
using namespace std;

int seq[8];
int vis[8];
int line1[16];
int line2[16];
string temp;
vector<string> ans;
void dfs(int *seq, int cur);
int main(void)
{
    memset(vis, 0, sizeof(vis));
    memset(line1, 0, sizeof(line1));
    memset(line2, 0, sizeof(line2));

    dfs(seq, 0);
    int n;
    cin >> n;
    int i;
    while(n--)
    {
        cin >> i;
        cout << ans[i-1] << endl;
    }
}

void dfs(int *seq, int cur)
{
    if(cur >= 8)
    {
        string t = "00000000";
        for(int i = 0; i < 8; i++)
            t[i] = seq[i] + '1';
        ans.push_back(t);
        //cout << t << endl;
        //cout << t <<  endl;
        //for(int i = 0; i < 16; i++)
        //    cout << line[i];
    }

    for(int i = 0; i < 8; i++)
    {
        if(vis[i]) continue;
        if(line1[cur - i + 8]) continue;
        if(line2[cur + i]) continue;

        vis[i] = 1;
        line1[cur - i + 8] = 1;
        line2[cur + i] = 1;
        seq[cur] = i;
        dfs(seq, cur + 1);
        vis[i] = 0;
        line1[cur - i + 8] = 0;
        line2[cur + i] = 0;
    }

}
