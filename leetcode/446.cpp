#include<cstdio>
#include<iostream>
#include<map>
#include<vector>
#include<climits>
using namespace std;

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        map<int, int> d[A.size()];
        
        int ans = 0;
        for(int i = 0; i < A.size(); i++)
        {
            for(int j = 0; j < i; j++)
            {
                long long diff = (long long)A[j] - (long long)A[i];
                if(diff > (1 << 30) || diff < (- (1<< 30) )) continue;
                int dif = (int)diff;

                int c1, c2;
                if(d[j].count(dif)) c1 = d[j][dif];
                else                c1 = 0;
                if(d[i].count(dif)) c2 = d[i][dif];
                else                c2 = 0;
                
                ans += c1;
                d[i][dif] = c1 + c2 + 1;
            }
        }
        return ans;
    }
};

int main(void)
{
    Solution s;
    vector<int> A;
    A.push_back(2);
    A.push_back(4);
    A.push_back(6);
    A.push_back(8);
    A.push_back(10);
    cout << s.numberOfArithmeticSlices(A) << endl;
    cout << INT_MAX << endl;
    cout << INT_MIN << endl;
}