#include<cstdio>
#include<iostream>
#include<vector>
#include<string.h>
using namespace std;

int sequence[20];
int main(void)
{
    int n;
    int first = 1;
    int kase = 0;
    while(cin >> n)
    {
        //if(first) first = 0;
        //else      cout << endl;     
        for(int i = 0; i < n; i++)
        {
            scanf("%d", sequence + i);
        }

        long long max = 0;
        for(int i = 0; i < n; i++)
        {
            
            for(int j = i; j < n; j++)
            {
                long long prod = 1;
                //cout << i << "," << j << endl;
                for(int k = i; k <= j; k++)
                {
                    prod *= sequence[k];
                }
                if(prod > max) max = prod;    
            }
            
        }
        kase++;
        printf("Case #%d: The maximum product is %lld.\n\n", kase, max);
        
    }
}