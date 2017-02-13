#include<cstdio>
#include<iostream>
#include <algorithm>
#include<vector>
#include<string.h>
#include<stack>
#include<math.h>
using namespace std;

int main(void)
{
    int n;
    while(1)
    {
        cin >> n;
        if(n == 0) break;
        
        int temp;
        for(int i = 0; i < n; i++)
        {
            cin >> temp;
            
            int cnt = 0;
            
            int j = 1;
            for(; j * j < temp; j++)
            {
                if(temp % j == 0) cnt+= 2;
            }
            if(j * j == temp) cnt++;
            cout << cnt << endl;
        }
        
    }
}

/*
#include<cstdio>
#include<iostream>
#include <algorithm>
#include<vector>
#include<string.h>
#include<stack>
#include<math.h>
using namespace std;

int main(void)
{
    int n;
    //while(cin >> n)
    //{
        long long temp;
        for(int i = 0; i < n; i++)
        {
            cin >> temp;
            
            int cnt = 0;
            

            for(int i = 1; i <= temp; i++)
            {
                if(temp % i == 0) cnt++;
            }
            cout << cnt << endl;
        }
        
    //}
}

*/