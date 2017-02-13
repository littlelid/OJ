#include<stdio.h>
#include<string.h>

int main(void)
{
    char s[500000];
    char t[500000];

    while(scanf("%s%s", s, t) != EOF)
    {
        int len_s = strlen(s);
        int len_t = strlen(t);

        int j = 0;
        int flag = 1;
        for(int i = 0; i < len_s; i++)
        {

            if(j >= len_t)
            {

                flag = 0;
                break;
            }
            for(; j < len_t; j++)
            {
                if(s[i] != t[j] && j == len_t - 1)
                {

                    flag = 0;
                    break;
                }
                if(s[i] == t[j])
                {

                    j++;
                    break;
                }

            }

            if(!flag)
            {
                break;
            }

        }
        if(flag)
        {
            printf("Yes\n");
        }
        else
        {
            printf("No\n");
        }
    }
}
