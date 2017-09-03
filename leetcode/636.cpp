#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdlib>
using namespace std;

class Solution {
public:
    int shoppingOffers(vector<int>& price, vector<vector<int> >& special, vector<int>& needs) {
        memset(costs, -1, sizeof(costs));
        specials = special;
        items_num = price.size();
        prices = price;
        costs[0] = 0;
        return dfs(needs);
    }


    int dfs(vector<int> needs) {
        int code = encode(needs);
        //cout << code << endl;
        if(costs[code] != -1) return costs[code];
         

        int ans = dot(needs, prices);    
        //cout << "dot:" << ans << endl;    
        for(vector<int> special : specials)
        {
            vector<int> new_needs;
            for(int j = 0; j < items_num; j++)
            {
                int temp = needs[j] - special[j];
                if (temp < 0) break;
                new_needs.push_back(temp);
            }
            //cout << "!!!" << endl; 
            if(new_needs.size() == items_num)
            {
                
                //cout << "***" << endl;
                int cost_temp = special[items_num] + dfs(new_needs);
                //cout << encode(new_needs) << ':' << cost_temp;
                ans = min(ans, cost_temp);
            }
        }
        costs[code] = ans;
        return ans;
    }

    int dot(vector<int> a, vector<int> b)
    {
        int ans = 0;
        for(int i = 0; i < a.size(); i++)
            ans += (a[i] * b[i]);
        return ans;
    }

    int encode(vector<int> needs){
        int code = 0;
        for(int i = 0; i < needs.size(); i++)
        {
            //cout << offers[i] << ' ';
            code += needs[i];
            code *= 10;
        }
        //cout << endl;
        code /= 10;
        return code;
    }


private: 
    int items_num;
    
    vector<vector<int> > specials;
    vector<int> prices;
    int costs[700100];
};
int main(void)
{
    vector<int> price;
    price.push_back(2); price.push_back(5);//price.push_back(0);


    vector<vector<int> >special;
    
    vector<int> t1;
    t1.push_back(3);t1.push_back(0); t1.push_back(5);//t1.push_back(4);
    vector<int> t2;
    t2.push_back(1);t2.push_back(2); t2.push_back(10);//t2.push_back(9);
    special.push_back(t1); 
    special.push_back(t2); 



    vector<int> needs;
    needs.push_back(3);needs.push_back(2);//needs.push_back(1);
    Solution s;
    cout << s.shoppingOffers(price, special, needs) << endl;


}