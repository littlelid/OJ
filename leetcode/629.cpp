#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int kInversePairs(int n, int k) {
        if(k > n*(n - 1 ) / 2) return 0;
        
        int NUM = 1000000007;
        //long long d[n + 1][k + 1];
        vector<int> d0(1005, 0);
        vector<int> d1(1005, 0);
        vector<int> d2(1005, 0);

        d0[0] = 1;
        for(int i = 1; i <= n; i++)
        {
            d1[0] = 1;
            
            cout << "1 ";
            for(int j = 1; j <= min(k, i * (i - 1) / 2 ); j++)
            {
                
                d1[j] = d0[j] + d1[j - 1];
                if(j - i >= 0 ) d1[j] -= d0[j - i];
                d1[j] = d1[j] % NUM;
                cout << d1[j] << ' ';
            }

            cout << endl;
            d0 = d1;
        }
        //cout << "***" << endl;
        return d1[0];
    }
};

int main(void)
{
    Solution s;
    s.kInversePairs(3, 1);

}