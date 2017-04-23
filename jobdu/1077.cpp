#include<cstdio>
#include<iostream>
#include<vector>
#include<string.h>
using namespace std;
long long nums[1000005];
long long max_sum(long long* nums, int l, int r);
int main(void)
{
    int n;
    while(cin >> n)
    {
        memset(nums, 0, sizeof(nums));
        for(int i = 0; i < n; i++)
        {
            cin >> nums[i];
        }
        cout << max_sum(nums, 0, n) << endl;
    }
}

long long max_sum(long long*  nums, int l, int r)
{
    if (r - l == 1) return nums[l];
    int m = l + (r - l) / 2;

    long long  temp1 = max_sum(nums, l, m);
    long long  temp2 = max_sum(nums, m, r);
    long long  temp = temp1 > temp2 ? temp1 : temp2;

    long long  l_sum = 0;
    long long  l_max = nums[m - 1];
    for(int i = m -1; i >= l; i--) 
    {
        l_sum += nums[i];
        if(l_max < l_sum) l_max = l_sum;
    }
    long  long r_sum = 0;
    long  long r_max = nums[m];
    for(int i = m; i < r; i++) 
    {
        r_sum += nums[i];
        if(r_max < r_sum) r_max = r_sum;
    }

    long long  f_max = l_max + r_max;
    return f_max > temp ? f_max : temp;
}
