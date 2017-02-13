#include<stdio.h>
#include<string.h>

int main(void)
{
    int T;
    scanf("%d", &T);
    char num2char[4];
    num2char[0] = 'A';
    num2char[1] = 'C';
    num2char[2] = 'G';
    num2char[3] = 'T';



    while(T--)
    {

        int m, n;
        scanf("%d %d", &m, &n);

        char input[m][n+1];
        for(int i = 0; i < m; i++)
        {
            scanf("%s", input[i]);
        }

        char output[n+1];
        int error = 0;

        for(int j = 0; j < n; j++)
        {
            int cnt[4];
            memset(cnt, 0, sizeof(cnt));
            for(int i = 0; i < m; i++)
            {
                if(input[i][j] == 'A')
                {
                    cnt[0]++;
                }
                else if(input[i][j] == 'C')
                {
                    cnt[1]++;
                }
                else if(input[i][j] == 'G')
                {
                    cnt[2]++;
                }
                else if(input[i][j] == 'T')
                {
                    cnt[3]++;
                }
            }
            int max_k;
            int max_ = 0;
            for(int k = 0; k < 4; k++)
            {
                if(cnt[k] > max_)
                {
                    max_ = cnt[k];
                    max_k = k;
                }
            }
            output[j] = num2char[max_k];
            error += (m- max_);
        }

        output[n] = '\0';
        printf("%s\n", output);
        printf("%d\n", error);

    }
}
