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
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        map<string, int> strings;
        for(int i = 0; i < words.size(); i++)
        {
            strings[words[i]] = 1;
        }

        vector<string> ans;
        for(int i = 0; i < words.size(); i++)
        {
            string s = words[i];
            if(s.size() == 0)  continue;
            stack<pair<int, int > > sta;
            int j = 0, len = 1;
            //cout << "i = " << i << endl;
            while(1)
            {
                if(j == s.size()) 
                {
                    ans.push_back(words[i]); 
                    //cout << "ans: " << words[i] << endl;
                    break;
                }

                if(j + len > s.size() || (j == 0 && len == s.size()))
                {    
                    if(sta.empty()) break;
                    else
                    {
                        j = sta.top().first;
                        len = sta.top().second;
                        len += 1;
                        sta.pop();
                        continue;
                    }    
                }
                
                //cout << '\t' << j << ' ' << len << endl;
                string t = s.substr(j, len);
                if(strings.count(t))
                {
                    
                    //cout << "\t match :" << t << " " << j << ' ' << len << endl; 
                    sta.push(make_pair(j, len) );
                    j = j + len;
                    len = 1;
                }
                else
                {
                    len += 1;
                }
            }

        }
        return ans;
    }
};

int main(void)
{
    Solution s;
    vector<string> words;
    //"cat","cats","catsdogcats","dog","dogcatsdog","hippopotamuses","rat","ratcatdogcat"
    //words.push_back("cat"); 
    //words.push_back("cats"); 
    //words.push_back("catsdogcat"); 
    //words.push_back("dog"); 
    //words.push_back("dogcatsdog"); 
    //words.push_back("hippopotamuses"); 
    //words.push_back("rat"); 
    //words.push_back("ratcatdogcat"); 
    words.push_back(""); 
    vector<string> ans = s.findAllConcatenatedWordsInADict(words);
    for(string s: ans) cout << s << endl;
}