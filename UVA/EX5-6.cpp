#include<cstdio>
#include<algorithm>
#include<iostream>
#include<vector>
#define BIAS 10000
#define MAXN 20050
using namespace std;
typedef vector<int> Vector;


int main(void)
{
    int T;
    cin >> T;
    while(T--)
    {
        Vector data[MAXN];
        int n;
        cin >> n;
        int a, b;
        while(n--)
        {
            cin >> a >> b;
            b += BIAS;

            data[b].push_back(a);
        }

        int flag = 1;
        int pole = 0;
        int sym = 1;
        for(int i = 0; i < MAXN; i++)
        {
            int len = data[i].size();
            if(len > 0)
            {
                sort(data[i].begin(), data[i].end());
                int ceil = (len / 2) + 1;
                for(int j = 0; j < ceil; j++)
                {
                    if(flag)
                    {
                        flag = 0;
                        pole = data[i][j] + data[i][len - 1 - j];
                    }
                    if(data[i][j] + data[i][len - 1 - j] != pole)
                    {
                        sym = 0;
                        break;
                    }
                }
            }
            if(sym==0)
            {
                break;
            }
        }
        if(sym)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

}
