#include<stdio.h>
#include<string.h>

int main(void)
{
    int T;
    scanf("%d", &T);

    int c[10];


    for(int i = 0; i < T; i++)
    {
        for(int i = 0; i < 10; i++)
        {
            c[i] = 0;
        }

        int n;
        scanf("%d", &n);
        for(int j = 1; j <= n; j++)
        {
            int num = j;
            while(num != 0)
            {
                c[num % 10] += 1;
                num /= 10;
            }
        }

        for(int k = 0; k < 10; k++)
        {
            if(k != 9)
                printf("%d ", c[k]);
            else
                printf("%d\n", c[k]);
        }

    }

}
