#include<cstdio>
#include<iostream>
#include<string>
#include<map>
#include<algorithm>

using namespace std;

int main(void)
{
    string s;
    while(cin >> s)
    {
        map<string, int> m;

        for(int i = 0; i < s.size(); i++)
        {
            for(int j = 1; j <= s.size() - i; j++ )
            {
                string tmp = s.substr(i, j);

                if(m.count(tmp)) m[tmp]++;
                else m[s.substr(i, j)] = 1;
            }
        }
        for(map<string, int>::iterator it = m.begin(); it != m.end(); it++)
        {
            if(it->second > 1)
            cout << it->first << ' ' << it->second << endl;
        }

    }


}
