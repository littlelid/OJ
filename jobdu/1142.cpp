#include<cstdio>
#include<iostream>

using namespace std;

int main(void)
{
    int p, e, i, d;
    int kase = 0;
    while(cin >> p >> e >> i >> d)
    {
        if(p == -1 && e == -1 && i == -1 && d == -1)
            break;
        // 23 28 33
        int ans;
        for(int k = d + 1; ; k++)
        {
            if((k - p) % 23 == 0 && (k - e) % 28 == 0 && (k - i) % 33 == 0) 
            {
                //cout << k + p << ' ' << k + e << ' ' << k + i << endl;
                ans = k;
                break;
            }
        }
        kase++;
        //printf("Case %d: the next triple peak occurs in %d days.\n", kase, ans - d);
        cout << "Case " << kase << ": the next triple peak occurs in " << ans - d << " days." << endl;
    
    }
}
