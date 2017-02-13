#include<iostream>
#include<vector>
#include<string>
#include<cstdio>

using namespace std;


int main(void)
{
    int mi[21];
    mi[0] = 1;
    for(int i = 1; i <= 21; i++)
    {
        mi[i] = mi[i - 1] * 2;
    }


    int T;
    cin >> T;

    while(T--)
    {
        int d, n;
        cin >> d >> n;

        int sum = 0;


        for(int i = d - 2; i >= 0; i--)
        {
            if(n > mi[i])
            {
                //cout << n <<" >= " << mi[i] << endl;
                sum += mi[d - 2 - i];
                //cout << mi[d - 2 - i] << " ";
                n -= mi[i];
            }

        }
        sum += mi[d - 1];
        cout << sum << endl;
    }
    int t;
    cin >> t;
    return 0;
}
