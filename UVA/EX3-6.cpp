#include<iostream>
#include<vector>
#include<string>
#include<cstdio>

using namespace std;


int main(void)
{
    int T;
    cin >> T;

    while(T--)
    {
        int d, n;
        cin >> d >> n;

        int sum = 1;
        int temp;
        for(int i = 1; i < d; i++)
        {
            sum *= 2;
            temp = n % 2;
            n /= 2;


            if( n!=0 )
            {
                sum += (1 - temp);
            }
        }
        cout << sum << endl;
    }
    int t;
    cin >> t;
    return 0;
}
