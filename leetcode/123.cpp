#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;

class Solution 
{
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() <= 1) return 0;
        int d[prices.size()][2];
        memset(d, 0, sizeof(d));

        int min_cache[prices.size()];
        int min_ = prices[0];
        for(int i = 0; i < prices.size(); i++)
        {
            min_ = min(min_, prices[i]);
            min_cache[i] = min_;
        } 

        for(int i = 0; i < prices.size(); i++)
        {
            d[i][0] = prices[i] - min_cache[i];
        }
        int max_cache[prices.size()];
        int max_ = d[0][0];
        for(int i = 0; i < prices.size(); i++)
        {
            max_ = max(max_, d[i][0]);
            max_cache[i] = max_;
        }

        int max_cache_2[prices.size()];
        int max_2 = max_cache[0] - prices[0];
        for(int i = 0; i < prices.size(); i++)
        {
            max_2 = max(max_2, max_cache[i] - prices[i]);
            max_cache_2[i] = max_2;
        }

        int ans = 0;
        for(int i = 0; i < prices.size(); i++)
        {
            ans = max(ans, prices[i] + max_cache_2[i]);
        }

        return ans;
    }
};


int main(void)
{
    Solution s;
    vector<int> prices;
    //prices.push_back(1);
    //prices.push_back(3);
    //prices.push_back(5);
    //prices.push_back(8);
    prices.push_back(11);
    prices.push_back(9);
    prices.push_back(7);
    prices.push_back(1);
    //prices.push_back(3);
    cout << s.maxProfit(prices) << endl;
}