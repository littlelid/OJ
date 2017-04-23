#include<cstdio>
#include<iostream>
#include<vector>

using namespace std;

int main(void)
{
    for(int i = 100; i <= 999; i++)
    {
        vector<int> v;
        int t = i;
        while(t != 0)
        {
            v.push_back(t % 10);
            t /= 10;

        }
        int sum = 0;
        for(int j = 0; j < v.size(); j++)
        {
            sum += v[j] * v[j] * v[j];
        }
        if(sum == i)
        {
            cout << i << endl;
        }
    }

}
