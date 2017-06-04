#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;

int max_height;
int max_ans;
int ans;
void dfs(vector<int> missle, int cur);
int main(void)
{
    int n;
    while(cin >> n)
    {
        max_height = 1 << 30;
        max_ans = -1;
        ans = 0;
        vector<int> missle;
        int temp;
        for(int i = 0; i < n; i++)
        {
            cin >> temp;
            missle.push_back(temp);
        }
        dfs(missle, 0);
        cout << max_ans << endl;
    
    }
}
void dfs(vector<int> missle, int cur)
{
    //for(int i = 0; i < cur; i++) cout << " ";
    //cout << cur << endl;
    if(cur >= missle.size())
    {
        if(ans > max_ans)
        {
            max_ans = ans;
            //for(int i = 0; i < cur; i++) cout << " ";
            //cout << "max_ans:"  << max_ans << endl;
        }
        return;
    }
    int max_expect = missle.size() - cur + ans;
    if( max_expect < max_ans) 
        return;

    int temp = max_height;
    if(max_height >= missle[cur])
    {
        max_height = missle[cur];
        ans += 1;
        //for(int i = 0; i < cur; i++) cout << " ";
        //cout << "Y" << endl;
        dfs(missle, cur + 1);
        ans -= 1;
        //for(int i = 0; i < cur; i++) cout << " ";
        //cout << "N" << endl;
        max_height = temp;
        dfs(missle, cur + 1);
    }
    else
    {
        //for(int i = 0; i < cur; i++) cout << " ";
        //cout << "N" << endl;
        dfs(missle, cur + 1);
    }
}
