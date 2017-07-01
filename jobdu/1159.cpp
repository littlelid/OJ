#include<cstdio>
#include<iostream>
#include<vector>
#include<string.h>
#include<algorithm>
using namespace std;

typedef vector<int> vec;

int main(void)
{
    int n;
    while(cin >> n)
    {
        vec times[105];
        vec pos;
        int p, d;
        int a_pos = -1;
        for(int i = 0; i < n; i++)
        {
            
            cin >> p >> d;
            pos.push_back(p);
            if(d == 1)
            {
                times[100 - p].push_back(1);
            }
            else if(d == -1)
            {
                times[p].push_back(-1);
            }
            else if(d == 0) a_pos = p;
        }
        sort(pos.begin(), pos.end());
        int a_order = 0;
        while(pos[a_order] != a_pos) a_order++;
        //cout << a_order << endl;

        int left = 0;
        int right = n - 1;
        int seq[105];
        memset(seq, -1, sizeof(seq));
        int cnt = 0;
        vector<int> time_order;
        for(int i = 1; i <= 99; i++)
        {
            for(int j = 0; j < times[i].size(); j++)
            {
                time_order.push_back(i);
                if(times[i][j] == 1 )
                {
                    seq[right] =  cnt;
                    cnt++;
                    right--;
                }
                else
                {
                    seq[left] = cnt;
                    cnt++;
                    left++;
                }
            }
        }
        //for(int i = 0; i < 10 ; i++) cout << seq[i] << ' ' ;
        //cout << endl;
        //for(int i = 0; i < time_order.size() ; i++) cout << time_order[i] << ' ' ;
        //cout << endl;
        int order = seq[a_order];
        //cout << order << endl;
        if(order == -1)
            cout << "Cannot fall!" << endl;
        else
            cout << time_order[order] << endl;
    }

}
