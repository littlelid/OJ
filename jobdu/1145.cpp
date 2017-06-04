#include<cstdio>
#include<iostream>

using namespace std;
int check(int* cir, int N);
int run(int * cir, int N);

int main(void)
{
    int N;
    while(cin >> N)
    {
        int cir[N];
        for(int i = 0; i < N; i++) cin >> cir[i];
        int cnt = 0; 
        while(check(cir, N) != 0)
        {
            run(cir, N);
            cnt += 1;
        }
        cout << cnt << ' ' << cir[0] << endl;
    
    }

}

int check(int* cir, int N)
{
    for(int i = 0; i < N; i++)
    {
        if(cir[i % N] != cir[(i + 1) % N]) return 0;
    }
    return 1;
}
int run(int * cir, int N)
{
    int new_cir[N];
    for(int i = 0; i < N; i++) new_cir[i] = cir[i];

    for(int i = 0; i < N; i++)
        cir[i] = new_cir[i] / 2 + new_cir[(i + 1) % N];

    for(int i = 0; i < N; i++)
        if(cir[i] % 2 == 1) cir[i] -= 1;
}
