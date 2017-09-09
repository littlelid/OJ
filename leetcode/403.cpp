#include<cstdio>
#include<iostream>
#include<vector>
#include<map>
using namespace std;

class Solution 
{
public:
    bool canCross(vector<int>& stones) 
    {
        this->stones = stones;
        
        for(int i = 0; i < stones.size(); i++)
        {
            //vector<int> d1;
            pos[stones[i]] = i;
            //pos_max = max(pos_max, stones[i]);
            /*
            for(int j = 0; j <= stones.size(); j++)
            {
                //d1.push_back(-1);
                d[i][j] = -1;
            }
            */
            //d.push_back(d1);
        }

        int ans = dfs(0,0);

        if(ans) return true;
        else    return false;
    }

    int dfs(int cur, int step)
    {
        if(cur == stones.size() - 1) return 1;
        if(cur > stones.size() - 1)  return 0;

        int code = encode(cur, step);
        if(d.count(code)) return d[code];
        
        
        int cur_pos = stones[cur];

        //cout << cur_pos << ' ' << step << endl;
        int ans = 0;
        if(step - 1 > 0 && pos.count(cur_pos + step - 1) ) 
            ans = max(ans, dfs( pos[cur_pos + step - 1] , step - 1) );

        if(step > 0 && pos.count(cur_pos + step ) ) 
            ans = max(ans, dfs( pos[cur_pos + step], step));

        if(step + 1 > 0 && pos.count(cur_pos + step + 1) )
            ans = max(ans, dfs( pos[cur_pos + step + 1], step + 1));

        d[code] = ans;
        return ans;
    }

    int encode(int cur, int step)
    {
        return 10000*cur + step;
    }

private:
    //vector<vector<int> > d;
    map<int, int> d;
    //vector<int>         pos;
    vector<int>         stones;
    //int   num_stones;
    map<int, int>            pos;
};

int main(void)
{
    Solution s;
    vector<int> stones;
    stones.push_back(0);
    stones.push_back(1);
    stones.push_back(3);
    stones.push_back(5);
    stones.push_back(6);
    stones.push_back(8);
    stones.push_back(12);
    stones.push_back(17);
    cout << s.canCross(stones) << endl;
}