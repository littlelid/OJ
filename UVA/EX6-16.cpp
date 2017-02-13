#include<iostream>
#include<cstdio>
#include<string.h>
using namespace std;

int father[26];
int degree_in[26];
int degree_out[26];
int flag[26];
int loc[2];
int idx = 0;
int G[26][26];

int find_f(int x);
int main(void)
{
    int T;
    cin >> T;
    while(T--)
    {

        memset(degree_in, 0,sizeof(degree_in));
        memset(degree_out, 0,sizeof(degree_out));
        memset(flag, 0,sizeof(flag));
        memset(G,0, sizeof(G));
        idx = 0;
        for(int i = 0; i < 26; i++)
        {
            father[i] = i;
        }

        int n;
        cin >> n;
        string s;
        while(n--)
        {
            cin >> s;
            int  ix0 = s[0] - 'a';
            int  ix1 = s[s.size() - 1] - 'a';

            if(G[ix0][ix1] == 0)
            {
                int f0 = find_f(ix0);
                int f1 = find_f(ix1);
                if(f0 < f1) father[ix1] = f0;
                else        father[ix0] = f1;
            }

            G[ix0][ix1] = 1;

            flag[ix0] = 1;
            flag[ix1] = 1;
            degree_in[ix0]++;
            degree_out[ix1]++;
        }

        int num = 0;

        for(int i = 0; i < 26; i++)
        {
            if(flag[i] && degree_in[i] != degree_out[i])
            {
                loc[idx] = i; idx = (idx + 1) % 2;

                num++;
            }

        }
        int flag1 = 0;
        if(num == 0)
        {
            flag1 = 1;
        }
        else if(num == 2)
        {
            int d0 = degree_in[loc[0]] - degree_out[loc[0]];
            int d1 = degree_in[loc[1]] - degree_out[loc[1]];
            if( (d0 == 1 && d1 == -1) || (d0 == -1 && d1 == 1) ) flag1 = 1;
        }
        int pos = 0;
        while(flag[pos] == 0) pos++;

        int father_one = find_f(pos);

        int flag2 = 1;

        for(int i = 0; i < 26; i++)
        {
            if(flag[i])
            {
                if(find_f(i) != father_one)
                {
                    flag2 = 0;
                    break;
                }
            }
        }
        if(flag1 && flag2) cout << "Ordering is possible." << endl;
        else               cout << "The door cannot be opened." << endl;
    }
}

int find_f(int x)
{
    if(father[x]!=x) father[x] = find_f(father[x]);
    return father[x];
}
