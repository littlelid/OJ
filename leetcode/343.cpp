#include<cstdio>
#include<iostream>
#include<string.h>
using namespace std;

class Solution {
public:
    int integerBreak(int n) {
        int d[100];
        memset(d, 0, sizeof(d));
        d[1] = 0;
        for(int i = 2; i <= n; i++)
        {
            //cout << i << endl;
            for(int j = 1; j < i; j++)
            {
                //cout <<  "\t" << max(j, d[j]) * max(i - j, d[i - j]) << endl;
                d[i] = max(d[i], max(j, d[j]) * max(i - j, d[i - j]) );
            }
            cout << d[i] << ' ';
        }
        cout << endl;

        return d[n];
    }
};

int main(void)
{
    Solution s;
    cout << s.integerBreak(15) << endl;
}