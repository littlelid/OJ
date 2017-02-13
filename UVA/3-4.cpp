#include<stdio.h>
#include<string.h>

int main(void)
{
    int N;
    scanf("%d", &N);

    char s[100];
    char s1[100];
    char s2[100];
    for(int i = 0; i < N; i++)
    {
        scanf("%s", s);
        int len = strlen(s);

        for(int j = 1; j <= len; j++)
        {
            int flag = 1;
            if(len % j != 0)
            {
                continue;
            }
            int t = len / j;


            for(int k = 0; k < t - 1; k++)
            {
                strncpy(s1, s + k * j, j);
                s1[j] = '\0';
                //printf("%d: %s\n", j, s1);
                strncpy(s2, s + (k + 1) * j, j);
                s2[j] = '\0';
                //printf("%d: %s\n", j, s1);
                //printf("len %d %d\n", strlen(s1), strlen(s2));
                //printf("cmp: %d\n", strcmp(s1, s2));
                if(strcmp(s1, s2) != 0)
                {
                    flag = 0;
                    break;
                }
            }
            if(flag)
            {
                if(i != N - 1)
                {
                    printf("%d\n\n", j);
                }
                else
                {
                    printf("%d\n", j);
                }
                break;

            }


        }


    }



}
