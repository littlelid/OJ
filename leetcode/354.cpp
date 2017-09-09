#include<cstdio>
#include<iostrea>
#include<vector>
#include<utility>
using namespace std;


class Solution {
public:
    int maxEnvelopes(vector<pair<int, int> >& envelopes) {
        for(int i = 0; i < envelopes.size(); i++)
            d.push_back(-1);
        this->envelopes = envelopes;

        int ans = 0;
        for(int i = 0; i < envelopes; i++)
        {
            ans = max(ans, dfs(i));
        }
        return ans;
    }

    int dfs(int cur)
    {
        if(d[cur] != -1) return d[cur];

        int ans = 0;
        for(int i = 0; i < envelopes.size(); i++)
        {
            if(envelopes[cur].first > envelopes[i].first && envelopes[cur].second > envelopes[i].second )
            {
                ans = max(ans, 1 + dfs(i));
            }
        }
        d[cur] = ans;

        return ans;
    }
private:
    vector<int> d;
    vector<pair<int, int> > envelopes;
};