#include<cstdio>
#include<iostream>
#include<math.h>
using namespace std;

int main(void)
{
    int N;
    while(cin >> N)
    {
        if (N == 0) break;
        for(int i = 0; i < N; i++)
        {
            int num;
            cin >> num;
            int ans = 0;
            int j;
            for(j = 2; j*j <= num; j++)
            {
                if(num % j == 0)
                    ans += 1;
            }
            
            ans += 1;    // 1
            ans *= 2;
            if ( (j- 1)*(j-1) == num) ans -= 1;
            cout << ans << endl;
        }
    
    }

}
