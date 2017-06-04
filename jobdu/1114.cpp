#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;

void dfs(vector<int> obj, int cur, int weight);
int ans;
int main(void)
{
    int n;
    int temp;
    while(cin >> n)
    {
        ans = 0;
        vector<int> obj;
        for(int i = 0; i < n; i++)
        { 
            cin >> temp;
            obj.push_back(temp);
        }
        dfs(obj, 0, 0);
        cout << ans << endl;
    }
}

void dfs(vector<int> obj, int cur, int weight)
{
    if(cur == obj.size())
    {
        if(weight == 40) ans += 1;
        return;
    }

    int temp = weight;

    if(weight < 40)
    {
        dfs(obj, cur + 1, weight + obj[cur]);
        dfs(obj, cur + 1, weight);
    }
    else
        dfs(obj, cur + 1, weight);


}
