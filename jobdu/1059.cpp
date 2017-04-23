#include<cstdio>
#include<iostream>
using namespace std;

int main(void)
{
    int a, b, c;
    for(int i = 0; i <= 9; i++)
    {
        for(int j = 0; j <= 9; j++)
        {
            for(int k = 0; k <= 9; k++)
            {
                int temp = i*100 + j*10 + k + j*100+ k*10 + k;
                if(temp == 532)
                {
                    cout << i << ' ' << j << ' ' <<  k << endl; 
                
                }
            
            }
        
        
        }
    
    
    }


}
