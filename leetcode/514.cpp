#include<cstdio>
#include<iostream>
#include<utility>
#include<vector>
using namespace std;

class Solution {
public:
    int findRotateSteps(string ring, string key) {
        vector<vector<pair<int, int> > > d;
        vector<vector<int> > position;

        int len = ring.size();

        for(int i = 0; i < 26; i++) 
        {
            vector<int> v_int;
            position.push_back(v_int);
        }
        for(int i = 0; i < ring.size(); i++)
        {
            position[ring[i] - 'a'].push_back(i);
        }

        for(int i = 0; i < key.size(); i++)
        {
            vector<int> p = position[key[i] - 'a'];

            vector<pair<int, int> > vec_pair; 
            cout << "choose size: " << p.size() << endl;
            for(int j = 0; j < p.size(); j++)
            {
                if(!i)
                {
                    vec_pair.push_back(make_pair(p[j], min( (p[j] - 0 + len) % len, (0 - p[j] + len) % len )  ) );
                    cout << "\tpush: " << p[j] << ' ' << min( (p[j] - 0 + len) % len, (0 - p[j] + len) % len) << endl; 
                }
                else
                {
                    
                    int new_step = 1 << 30;
                    for(int k = 0; k < d[i - 1].size(); k++)
                    {
                        int pos = d[i -1][k].first;
                        int step = d[i - 1][k].second;
                        
                        new_step = min(new_step, step + min( (p[j] - pos + len) % len, (pos - p[j] + len) % len ) ); 
                    }
                    vec_pair.push_back(make_pair(p[j], new_step));
                    cout << "\tpush: " << p[j] << ' ' <<  new_step << endl;
                }
            }
            d.push_back(vec_pair);
        }

        int ans = 1<<30;
        for(int i = 0; i < d.back().size(); i++)
        {
            ans = min(ans, d.back()[i].second);
        }
        ans += key.size();
        return ans;
    }
};

int main(void)
{
    Solution s;
    //cout << s.findRotateSteps("godding", "gd") << endl;
    cout << s.findRotateSteps("godding", "gid") << endl;
}