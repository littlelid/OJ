#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int d[amount + 1];
        memset(d, -1, sizeof(d));
        d[0] = 0;
        for(int i = 0; i < amount; i++)
        {
            if(d[i] == -1) continue;
            for(int j = 0; j < coins.size(); j++)
            {
                long long temp = 0;
                temp += coins[j];
                temp += i;
                //if(coins[j] == 2147483647) return 0;
                //cout << i << ' ' << j << ':' << temp << ' ' << amount << endl;
                if(temp > amount) continue;
                //cout << i << ' ' << j << endl;
                if(d[i + coins[j]] == -1) d[i + coins[j]] = d[i] + 1;
                else
                {
                    d[i + coins[j]] = min(d[i + coins[j]], d[i] + 1);
                } 
            }
        }
        //for(int i = 0; i <= amount; i++)
        //    cout << d[i] << ' ';
        //cout << endl;
        return d[amount];
    }
};
int main(void)
{
    Solution s;
    s.coinChange()
}