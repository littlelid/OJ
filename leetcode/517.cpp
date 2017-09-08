#include<cstdio>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

class Solution {
public:
    int findMinMoves(vector<int>& machines) {
        int size = machines.size();
        if(size == 0) return 0;
        vector<int> sums;

        sums.push_back(0);
        sums.push_back(machines[0]);
        //int max_dress = -1;
        for(int i = 1; i < size; i++)
        {
            sums.push_back(sums[i] + machines[i]);
        }
        //cout << "*1*" << endl;
        int avg;
        if(sums[size] % size != 0) return -1;
        else                       avg = sums[size] / size;

        int ans = 0;
        int left, right;
        cout << avg << endl;
        for(int i = 0; i < size; i++)
        {
            left = avg * i - sums[i];
            right = avg * (size - i - 1) - (sums[size] - sums[i + 1]);
            cout << i << ": " << left << ", " << right << endl;
            cout << "\t" << sums[i] << endl;
            if(left < 0 && right < 0) ans = max(ans, abs(left - right) );
            else if(left >=0 && right >= 0) ans = max(ans, abs(left + right) );
            else
            {
                ans = max(ans, abs(left));
                ans = max(ans, abs(right));
            }
        }
        
        
        return ans;
    }
};

int main(void)
{
    Solution s;
    vector<int> machines;
    machines.push_back(0);
    machines.push_back(3);
    machines.push_back(0);
    cout << s.findMinMoves(machines) << endl;
}