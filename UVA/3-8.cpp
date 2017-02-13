#include<stdio.h>
#include<string.h>
int main(void)
{
    int a, b;
    int first = 1;
    while(scanf("%d %d", &a, &b) != EOF)
    {
        if(first != 1)
        {
            printf("\n");

        }

        int org_a = a;
        int org_b = b;

        int shang[100];

        int position[3005];
        int flag = 0;
        int next_position = -1;
        memset(shang, 0, sizeof(shang));
        memset(position, -1, sizeof(position));


        shang[0] = a / b;
        a = a % b;



        for(int i = 1; i <= 4000; i++)
        {
            position[a] = i;
            a *= 10;
            shang[i] = a / b;

            a = a % b;
            if(position[a] != -1)
            {
                next_position = i + 1;
                break;
            }

        }

        printf("%d/%d = ", org_a, org_b);
        printf("%d.", shang[0]);

        int start = position[a];
            //printf("###: %d\n", start);
        int end_ = next_position;
        int len = end_ - start;

        if(start - 1 <= 50)
        {
            for(int i = 1; i < start; i++)
            {
                printf("%d", shang[i]);
            }
            printf("(");

            if(len <= 50 - start + 1)
            {
                for(int i = start; i < end_; i++)
                {
                    printf("%d", shang[i]);
                }
                printf(")\n");

            }
            else
            {
                for(int i = start; i <= 50; i++)
                {
                    printf("%d", shang[i]);
                }
                printf("...)\n");
            }

        }
        else
        {
            for(int i = 1; i <= 50; i++)
            {
                printf("%d", shang[i]);
            }
            printf("\n");
        }


        printf("   %d = number of digits in repeating cycle\n", len);

        first = 0;

    }


}
