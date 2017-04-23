#include<cstdio>
#include<iostream>
#include<string.h>
#include<string>
using namespace std;

int main(void)
{
    int L, M;
    while(scanf("%d%d", &L, &M) == 2)
    {
        int road[L + 1];
        for(int i = 0; i <= L; i++) road[i] = 1;
        int a, b;
        while(M--)
        {
            cin >> a >> b;
            for(int i = a; i <= b; i++) road[i] = 0;
        }

        int cnt = 0;
        for(int i = 0; i <= L; i++){ cnt += road[i];}

        cout << cnt << endl;
    }
}
