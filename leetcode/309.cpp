#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> dp;
        dp.push_back(0);
        
        for(int i = 1; i < prices.size(); i++)
        {
            dp.push_back(0);
            for(int j = 0; j < i; j++)
            {
                int part1 = 0;
                if(j >= i - 2) part1 = 0;    
                else           part1 = dp[j];
                
                int part2 = 0;
                int k;
                if(j >= i - 2) k = j;
                else           k = j + 2;
                
                for(; k < i; k++)
                {
                    if(prices[i] - prices[k] > part2) part2 = prices[i] - prices[k];
                }
                dp[i] = max(dp[i], part1 + part2);
                cout << i << ':' << part1 << '+' << part2 << endl;
            }
            for(int k = 0; k < i; k++)
                dp[i] = max(dp[i], prices[i] - prices[k]);
        }
        int max_profit = 0;
        for(int i = 0; i < dp.size(); i++)
        {
            max_profit = max(max_profit, dp[i]);
            cout << dp[i] << ' ';
        }
        cout << endl;
        return max_profit;
    }
};

int main(void)
{
    Solution s;
    vector<int> prices;
    prices.push_back(6);
    prices.push_back(1);
    prices.push_back(3);
    prices.push_back(2);
    prices.push_back(4);
    prices.push_back(7);
    cout << s.maxProfit(prices) << endl;
}