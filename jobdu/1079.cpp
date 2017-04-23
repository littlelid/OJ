#include<cstdio>
#include<iostream>
#include<string>
using namespace std;

int cnt[26] = {1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,4,1,2,3,1,2,3,4};
int bnt[26] = {1,1,1,2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,6,7,7,7,8,8,8,8};
int main(void)
{
    string s;
    while(cin >> s)
    {
        int t = 0;
        for(int i = 0; i < s.size(); i++)
        {
            //cout << s << endl;
            if(i && bnt[s[i - 1]-'a'] == bnt[s[i] - 'a'])
            {
                 t += 2;
                 //cout << s[i - 1] << ' ' <<  bnt[s[i - 1]-'a'] << ", " <<  s[i] << " " << bnt[s[i]-'a'] << endl;
            }
            t += cnt[s[i]- 'a'];
            //cout << "\t" << s[i]  << ": " << cnt[s[i]- 'a'] << endl;
        }
        cout << t << endl; 
    }

}
