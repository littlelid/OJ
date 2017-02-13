#include<stdio.h>
#include<string.h>
#define TEST 1

char m[15][15];
int readboard();
void printboard();
int main()
{
    printf("***");
    while(readboard())
    {
        printboard();
    }
}

int readboard()
{
    memset(m, '*', sizeof(m));

    int n, x, y;
    scanf("%d%d%d", &n, &x, &y);
    m[x][y] = 'B';

    if(n==0 && x==0 && y==0)
    {
        if(TEST) printf("END\n");
        return 0;
    }
    else
    {
        for(int i = 0; i < n; i++)
        {
            //printf("readboard--- i:%d\n", i);
            getchar();
            char ch;
            scanf("%c %d %d", &ch, &x, &y);

            m[x][y] = ch;
        }
        //printf("readboard...end\n");

    }
    return 1;
}

void printboard()
{
    for(int i = 1; i <= 10; i++)
    {
        for(int j = 1; j <= 9; j++)
        {
            printf("%c", m[i][j]);
        }
        printf("\n");
    }

}
