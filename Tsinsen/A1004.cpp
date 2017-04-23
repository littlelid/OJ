#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;

int main(void)
{
    int m[25][25];
    for(int i = 0; i < 25; i++)
    {
        for(int j = 0; j <= i; j++)
        {
            m[i][j] = i - j;  
        }
        for(int k = i + 1; k < 25; k++)
        {
            m[i][k] = k - i;
        }
     }
    int a, b;
    while(scanf("%d %d", &a, &b) == 2)
    {
        for(int i = 0; i < a; i++)
        {
            for(int j = 0; j < b; j++) 
            {
                printf("%c", m[i][j] + 'A');
            }
            cout << endl;
    
        }
    }
}
