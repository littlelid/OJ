#include<cstdio>
using namespace std;

int main(void)
{
    int x;

    while(scanf("%d", &x) == 1)
    {
        int sum = 0;
        for(int i = 1; i <= x; i++)
        {
            sum += i;
        }


        printf("%d\n\n", sum);


    }

}
