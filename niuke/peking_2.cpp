#include<cstdio>
#include<iostream>
#include<string.h>
#include<vector>
using namespace std;


int readers[300];
int books[300];

int main(void)
{
    int N, M;
    while(cin >> N)
    {
        cin >> M;
        
        memset(readers, 0, sizeof(readers));
        memset(books, 0, sizeof(books));
        int b;
        for(int i = 0; i < N; i++)
        {
            cin >> b;
            readers[i] = b;
            books[b] += 1;
        }
        
        for(int i = 0; i < N; i++)
        {
            int num = books[readers[i]];
            num--;
            if(num)
            {
                cout << num << endl; 
            }
            else
            {
                cout << "BeiJu" << endl;
            }
        }
    }
}