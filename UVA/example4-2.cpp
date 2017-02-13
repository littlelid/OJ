#include<stdio.h>
#include<string.h>

int main(void)
{





    while(1)
    {
        int T;
        scanf("%d", &T);
        if(T == -1)
        {
            break;
        }
        char s1[100];
        char s2[100];
        int cnt[26];
        int visit[26];
        scanf("%s%s", s1, s2);
        memset(visit, 0, sizeof(visit));
        memset(cnt, 0, sizeof(cnt));
        int len1 = strlen(s1);
        int len2 = strlen(s2);



        for(int i = 0; i < len1; i++)
        {

            cnt[s1[i] - 'a'] += 1;
            //printf("%c: %d\n", s1[i], cnt[s1[i] - 'a']);
        }



        int correct = 0;
        int error = 0;
        int flag = -1;



        for(int i = 0; i < len2; i++)
        {
            //printf("visit %c %d error %d\n", s2[i], visit[s2[i] - 'a'], error);

            if(visit[s2[i] - 'a'] == 1)
            {
                //printf("###\n");
                error++;
                if(error >=7)
                {
                    //printf("%%%\n");
                    flag = 0;
                    break;
                }
                continue;

            }
            if(cnt[s2[i] - 'a'] != 0)
            {
                //printf("!!!   %c   %d\n", s2[i], cnt[s2[i] - 'a']);
                correct += cnt[s2[i] - 'a'];

                visit[s2[i] - 'a'] = 1;
                cnt[s2[i] - 'a'] = 0;
                //printf("&&& correct %d len2 %d\n", correct, len2);
                if(correct == len1)
                {
                    flag = 1;
                    break;
                }
            }
            else
            {
                error++;
                if(error >=7)
                {
                    //printf("%%%\n");
                    flag = 0;
                    break;
                }
            }



        }

        printf("Round %d\n", T);
        if(flag == 1)
        {
            printf("You win.\n");
        }
        else if(flag == 0)
        {
            printf("You lose.\n");

        }
        else
        {
            printf("You chickened out.\n");
        }

    }
}
