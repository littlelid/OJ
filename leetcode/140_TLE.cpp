#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<stack>
#include<utility>
using namespace std;

class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        map<string, int> strings;
        for(int i = 0; i < wordDict.size(); i++) strings[wordDict[i]] = 1;
        
        int start = 0, len = 1;
        //stack<int> 
        vector<string> ans;
        if(s.size() == 0 )
        {
            if(strings.count("")) ans.push_back("");

            return ans;
            
        }
        vector<pair<int, int> > sta;
        vector<string> ans_temp;
        while(1)
        {
            //cout << start << ' ' << len << endl;
            if(start + len > s.size() )
            {
                if(start == s.size())
                {
                    
                    string m = ans_temp[0];
                    for(int i = 1; i < ans_temp.size(); i++)
                    {
                        //cout << ans_temp[i] << endl;
                        
                        m = m + " " + ans_temp[i];
                        
                    }
                    cout << m << endl;
                    ans.push_back(m);
                }

                if(sta.empty()) break;
                else
                {
                    start = sta.back().first;
                    len   = sta.back().second;
                    len += 1;
                    sta.pop_back();
                    ans_temp.pop_back();

                    continue;
                }
                
            }

            string t = s.substr(start, len);
            if(strings.count(t))
            {
                cout << "\tmatch: " << t << ' ' << start << ' ' << len << endl; 
                ans_temp.push_back(t);
                sta.push_back(make_pair(start, len));

                start = start + len;
                len = 1;
            }
            else
            {
                len++;
            }
            
        }
        return ans;
    }
};

int main(void)
{
    Solution s;
    vector<string> wd;
    string t = "catsanddog";
    cout << "\t" << t.substr(10).size() << ' ' << t.substr(0, 1) << endl;
    wd.push_back("cat");
    wd.push_back("cats");
    wd.push_back("and");
    wd.push_back("sand");
    wd.push_back("dog");
    s.wordBreak(t, wd);
}