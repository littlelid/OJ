#include<cstdio>
#include<iostream>
#include<vector>
#include<map>
using namespace std;
const int MAX_COL = 15;

const int MAG = 50000;
int n, m;

vector<string>   str_cache;
map<string, int> ID_cache;
vector<int>      data[MAX_COL];
map<int, int>    appear;
int ID(string s)
{
    if(ID_cache.count(s)) return ID_cache[s];

    str_cache.push_back(s);
    return ID_cache[s] = str_cache.size() - 1;
}

void read()
{
    string str;
    char  ch;

    getchar();
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {

            while(1)
            {
                ch = getchar();
                if(ch == '\n' || ch == '\r' || ch == ',')
                {
                    data[j].push_back(ID(str));
                    break;
                }
                str += ch;
            }
            str.clear();
        }

    }
}

void solve()
{
    for(int i = 0; i < m; i++)
    {

        for(int j = i + 1; j < m; j++)
        {


            appear.clear();
            for(int k = 0; k < n; k++)
            {
                int x1 = data[i][k];
                int x2 = data[j][k];
                int code = x1 * MAG + x2 ;
                if(appear.count(code))
                {
                    cout << "NO" << endl;
                    cout << appear[code] + 1 << " " << k + 1<< endl;
                    cout << i + 1<< " " << j + 1<< endl;
                    return;
                }
                else
                {
                    appear[code] = k;
                }

            }
        }
    }
    cout << "YES" << endl;
    return;
}



int main(void)
{
    while(cin >> n >> m)
    {
        read();

        solve();

        str_cache.clear();
        ID_cache.clear();
        for(int i = 0; i < MAX_COL; i++) data[i].clear();
    }
}



