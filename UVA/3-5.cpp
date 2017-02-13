#include<stdio.h>
#include<string.h>

int main(void)
{
    int r;
    int c;
    int num = 0;

    int first_puzzle = 1;
    while(1)
    {
        num++;
        scanf("%d", &r);
        if(r == 0) break;

        if(first_puzzle)
        {
            first_puzzle = 0;
        }
        else
        {
            printf("\n");
        }
        scanf("%d", &c);

        char p[r][c];
        int  m[r][c];
        char s[20];

        for(int i = 0; i < r; i++)
        {
            scanf("%s", s);
            for(int j = 0; j < c; j++)
            {
                p[i][j] = s[j];
            }

        }

        int cnt = 0;
        for(int i = 0; i < r; i++)
        {
            for(int j = 0; j < c; j++)
            {
                m[i][j] = 0;
                if(p[i][j] == '*')
                {
                    continue;
                }
                if(i == 0 || j == 0)
                {
                    cnt++;
                    m[i][j] = cnt;
                }
                else if(p[i - 1][j] == '*' || p[i][j-1] == '*')
                {
                    cnt++;
                    m[i][j] = cnt;
                }
            }
        }

        printf("puzzle #%d:\n", num);
        printf("Across\n");

/*
        int mark[r];
        for(int i = 0; i < r; i++)
        {
            mark[i] = 0;
        }
*/
        for(int i = 0; i < r; i++)
        {
                int start = 0;
                for(int j = 0; j < c; j++)
                {
                    if(p[i][j] == '*')
                    {
                        start = j + 1;
                        continue;
                    }
                    if( p[i][j] != '*' && ( j == c - 1 || p[i][j + 1] == '*') )
                    {
                        printf("%3d.", m[i][start]);
                        for(int k = start; k <= j; k++)
                        {
                            printf("%c", p[i][k]);
                        }
                        printf("\n");


                    }

                }
        }


        printf("Down\n");
        int starts[c];
        for(int j = 0; j < c; j++)
        {
            starts[j] = 0;
        }

        int flags[r][c];
        for(int i = 0; i < r; i++)
        {
            for(int j = 0; j < c; j++)
            {
                flags[i][j] = 1;
            }
        }

        for(int i = 0; i < r; i++)
        {
            for(int j = 0; j < c; j++)
            {
                if(flags[i][j] && m[i][j])
                {
                    //printf("flags[%d][%d] = %d     ", i, j, flags[i][j]);
                    printf("%3d.", m[i][j]);
                    for(int k = i; k < r; k++)
                    {
                        printf("%c", p[k][j]);
                        flags[k][j] = 0;

                        if(k < r - 1 && p[k+1][j] == '*')
                        {
                            break;
                        }

                    }
                    //printf("        flags[%d][%d] = %d", i, j, flags[i][j]);
                    printf("\n");

                }
            }
        }


    }



}
