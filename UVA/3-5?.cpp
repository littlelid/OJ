#include<stdio.h>
#include<string.h>

int main(void)
{
    char m[5][5];
    char ch;
    ch = getchar();
    int x;
    int y;
    int num = 1;
    while(ch != 'Z')
    {
        if(num != 1)
        {
            printf("\n");
        }

        for(int i = 0; i < 5; i++)
        {
            for(int j = 0; j < 5; j++)
            {
                m[i][j] = ch;
                if(ch == ' ')
                {
                    x = i;
                    y = j;
                }
                ch = getchar();
            }
            ch = getchar();
            //printf("herer: %c\n", ch);
        }

        int flag = 1;
        while(ch != '0')
        {
            while(ch == ' ' || ch == '\n')
            {
                ch = getchar();
            }
            if((ch == 'A' && x == 0) || (ch == 'B' && x == 4) || (ch == 'L' && y == 0) || (ch == 'R' && y == 4))
            {
                flag = 0;
                break;
            }



            if(ch == 'A')
            {
                m[x][y] = m[x - 1][y];
                x -= 1;
                m[x][y] = ' ';
            }
            else if(ch == 'B')
            {
                m[x][y] = m[x + 1][y];
                x += 1;
                m[x][y] = ' ';
            }
            else if(ch == 'L')
            {
                m[x][y] = m[x][y - 1];
                y -= 1;
                m[x][y] = ' ';
            }
            else if(ch == 'R')
            {
                m[x][y] = m[x][y + 1];
                y += 1;
                m[x][y] = ' ';
            }
            else
            {
                flag = 0;
                break;
            }


            ch = getchar();
        }

        if(flag == 0)
        {
            while(ch != '0')
            {
                ch = getchar();
            }
        }

        getchar();
        ch = getchar();



        printf("Puzzle #%d:\n", num);
        if(flag == 0)
        {
            printf("This puzzle has no final configuration.\n");
        }
        else
        {
            for(int i = 0; i < 5; i++)
            {
                printf("%c %c %c %c %c\n", m[i][0], m[i][1], m[i][2], m[i][3], m[i][4]);
            }
        }

        num += 1;
    }
    printf("\n");
    return 0;
}

