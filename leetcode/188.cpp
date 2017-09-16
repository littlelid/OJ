#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if(prices.size() <= 1) return 0;
        vector<int> d_before(prices.size(), 0);
        vector<int> max_before(prices.size()), max_now(prices.size());
        int ans = 0;
        for(int i = 0; i < k; i++)
        {
            int max_ = d_before[0];
            for(int j = 0; j < max_before.size(); j++)
            {
                max_ = max(max_, d_before[j]);
                max_before[j] = max_;
            }

            max_ = max_before[0] - prices[0];
            for(int j = 0; j < max_now.size(); j++)
            {
                max_ = max(max_, max_before[j] - prices[j]);
                max_now[j] = max_;
            }
            vector<int> d_now(prices.size(), 0);
            for(int j = 0; j < d_now.size(); j++)
            {
                d_now[j] = prices[j] + max_now[j];
                ans = max(ans, d_now[j]);
            }
            if(d_before == d_now) {cout << "*" << endl; break;}
            //d_before = d_now;
            swap(d_before, d_now);
        }      
        //if 
        return ans;
    }
};



int main(void)
{
    Solution s;
    vector<int> prices;
    
    prices.push_back(1);
    prices.push_back(3);
    prices.push_back(5);
    prices.push_back(4);
    prices.push_back(7);
    prices.push_back(9);
    
    cout << s.maxProfit(9, prices) << endl;
}