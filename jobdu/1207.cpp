#include<cstdio>
#include<iostream>
#include<math.h>
using namespace std;

int main(void)
{
    int num;
    while(cin >> num)
    {
        int keep = num;
        int cnt = 0;
        int i = 2;
        int sq = (int)sqrt(num);

        while(i <= sq)
        {
            if(num % i == 0)
            {
                num /= i; 
                cnt += 1;
                if(num == 1) break;
            }
            else
            {
                i++;
            }
        }
        if(num > sq) cnt++;
        if(keep == num) cnt = 1;
        cout << cnt << endl; 
    }

}
