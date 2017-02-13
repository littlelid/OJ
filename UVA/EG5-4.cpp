#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
#include<cctype>

using namespace std;

vector<string> words;
map<string, int> cnt;

string norm(string s)
{
    string ans = s;
    for(int i = 0; i < ans.size(); i++)
    {
        ans[i] = tolower(ans[i]);
    }
    sort(ans.begin(), ans.end());

    return ans;
}

int main(void)
{
    string s;
    while(1)
    {
        cin >> s;

        if(s[0] == '#')
        {
            break;
        }

        words.push_back(s);

        string temp = norm(s);

        if(!cnt.count(temp)) cnt[temp] = 0;
        cnt[temp]++;
    }

    vector<string> out;
    for(int i = 0; i < words.size(); i++)
    {
        string word = words[i];

        if(cnt[norm(word)] == 1) out.push_back(word);
    }
    sort(out.begin(), out.end());

    for(int i = 0; i < out.size(); i++)
    {
        cout<<out[i]<<endl;
    }

}
