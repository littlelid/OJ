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
        
        vector<string> ans = wordBreak(s, strings);
        for(string a: ans) cout << a << endl;
        return ans;
    }

    vector<string> combine(string s, vector<string> after)
    {
        for(int i = 0; i < after.size(); i++)
        {
            after[i] = s + " " + after[i];
            //cout << '\t' << i << ' ' << after[i] << endl;
        }
        return after;
    }
    vector<string> wordBreak(string s, map<string, int>& wordDict) {
        if(d.count(s)) return d[s];
        cout << s << endl;
        vector<string> ans;
        if(wordDict.count(s)) ans.push_back(s);
        for(int i = 1; i < s.size(); i++)
        {
            string word = s.substr(0, i);
            if(wordDict.count(word))
            {
                cout << "\tmatch " << word << endl;
                string t = s.substr(i);
                vector<string> ans_after = combine(word, wordBreak(t, wordDict) );
                //cout << "ans_after size: " << ans_after.size() << endl;
                ans.insert(ans.end(), ans_after.begin(), ans_after.end());
            }
        }
        d[s] = ans;

        return ans;
    }
private:
    map<string, vector<string> > d;

};

int main(void)
{
    Solution s;
    vector<string> wd;
    string t = "catsanddog";
    //cout << "\t" << t.substr(1) << ' ' << t.substr(0, 1) << endl;
    wd.push_back("cat");
    wd.push_back("cats");
    wd.push_back("and");
    wd.push_back("sand");
    wd.push_back("dog");
    s.wordBreak(t, wd);
}