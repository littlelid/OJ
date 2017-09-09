#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int numSquares(int n) {
        this->n = n;
        for(int i = 0; i <= n; i++)
        {
            d.push_back(-1);
        }        

        d[0] = 0; d[1] = 1;
        dfs(n);
        //cout << d[]
        //for(int i = 1; i <= n; i++)
        //    cout << d[i] << ' ';
        //cout << endl;
        return d[n];
    }

    int dfs(int i)
    {
        if(d[i] != -1) return d[i];

        int ans = 1<<30;
        for(int j = 1; j*j <= i; j++)
        {
            ans = min(ans, 1 + dfs(i - j*j) );
        }
        d[i] = ans;

        return ans;

    }
private:
    vector<int> d;
    int n;
};


int main(void)
{
    Solution s;
    cout << s.numSquares(14) << endl;
}