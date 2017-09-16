#include<cstdio>
#include<iostream>
using namespace std;

class Solution {
public:
    int checkRecord(int n) {
        memset(d, 0, sizeof(d));
        memset(d[n], 1, sizeof(d[n]));
        d[n][0][0] = 1;
        d[n][0][1] = 1;
        d[n][0][2] = 1;
        d[n][1][0] = 1;
        d[n][1][1] = 1;
        d[n][1][2] = 1;
        this->n = n;
        MOD = 1000000007;
        for(int idx = n - 1; idx >= 0; idx--)
        {
            for(int num_abs = 0; num_abs < 2; num_abs++)
            {
                for(int num_late = 0; num_late < 3; num_late++)
                {
                    long long ans = 0;
                    if(num_abs < 1)
                    {
                        ans += d[idx + 1][num_abs + 1][0]; // choose Absent
                        ans = (ans + MOD) % MOD;
                    }
                    if(num_late < 2)
                    {
                        ans += d[idx + 1][num_abs][num_late + 1];  // choose Late
                        ans = (ans + MOD) % MOD;
                    }
                    ans += d[idx + 1][num_abs][0]; // choose Present
                    ans = (ans + MOD) % MOD;
                    d[idx][num_abs][num_late] = (int)ans;
                    //cout << ans << endl;
                    //printf("(%d, %d, %d): ans = %d\n", idx, num_abs, num_late, (int)ans);
                }
            }
        }        
        
        
        return d[0][0][0];
    }

private:
    int d[100000 + 1][2][3];
    int n;
    int MOD;

};
int main(void)
{
    Solution s;
    //cout << s.checkRecord(100000) << endl; 
    cout << s.checkRecord(100000) << endl; 
}