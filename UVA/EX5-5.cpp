#include<cstdio>
#include<iostream>
#include<map>
#include<algorithm>
#include<vector>
using namespace std;

map<string, int> dict;
map<string, int>::iterator it;
vector<string> out;

int main()
{
    string s;
    while(cin >> s)
    {
        dict[s] = 1;
    }

    for (it = dict.begin(); it != dict.end(); ++it)
    {
        string t = (it->first);
        int len = t.size();
        for(int i = 1; i < len - 1; i++)
        {
            string s1 = t.substr(0, i);
            string s2 = t.substr(i, len - i);
            if(dict.count(s1) && dict.count(s2))
            {
                out.push_back(t);
            }

        }

    }

    sort(out.begin(), out.end());
    out.erase(unique(out.begin(), out.end()), out.end());
    for(int i = 0; i < out.size(); i++)
    {
        cout << out[i] << endl;
    }

}
