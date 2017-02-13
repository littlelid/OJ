#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;

int main(void)
{
    int k;
    while(cin >> k)
    {
        vector<int> ans;
        for(int y = k + 1; y <= 2 * k; y++)
        {
            int x = (k * y) / (y - k);
            if(x * (y - k) == k * y)
            {
                ans.push_back(y);
            }
        }

        cout << ans.size() << endl;
        for(int i = 0; i < ans.size(); i++)
        {
            int y = ans[i];
            int x = (k * y) / (y - k);
            printf("1/%d = 1/%d + 1/%d\n", k, x, y);
        }

    }

}