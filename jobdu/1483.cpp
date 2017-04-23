#include<cstdio>
#include<iostream>
#include<string>
#include<queue>
#include<string.h>
using namespace std;

int N;
struct T
{
    string s;   
    int   cnt;
    T(string s, int cnt):s(s), cnt(cnt){}
};
int hash_(string s);
int check(string s);
int visit[1600000];
int main(void)
{
    while(cin >> N)
    {
        memset(visit, 0, sizeof(visit));
        string s;
        cin >> s;
        queue<T> q;

        visit[hash_(s)] = 1;
        q.push(T(s, 0));
        int ans = -1;
        char ch;
        while(!q.empty())
        {
            T t = q.front(); q.pop();

            if(check(t.s))
            {
                ans = t.cnt;
                break;
            }

            for(int i = 0; i < t.s.size() - 1; i++)
            {
                string new_s(t.s);
                ch = new_s[i]; new_s[i] = new_s[i + 1]; new_s[i + 1] = ch;
                int h = hash_(new_s);
                if(!visit[h])
                {
                    q.push(T(new_s, t.cnt + 1));
                    visit[h] = 1;
                }
            }
        }

        cout << ans << endl;
    }
}

int hash_(string s)
{
    int sum = 0;
    for(int i = 0; i < s.size(); i++)
    {
        sum *= 3;
        sum += s[i] - '0';
    }
    return sum;
}

int check(string s)
{
    for(int i = 0; i + 3 < s.size(); i++)
    {
        if(s[i] == '2' && s[i + 1] == '0' && s[i + 2] == '1' && s[i + 3] == '2')
        {
            return 1;
        }
    }
    return 0;
}
