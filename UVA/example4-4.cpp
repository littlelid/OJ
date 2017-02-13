#include<stdio.h>
#include<string.h>

char readchar();
int readint(int len);

int code[8][1<<8];
int readcode();
void printcode();
int main(void)
{
    while(readcode())
    {

        //printcode();
        //printf("**********\n");
        while(1)
        {
            int len = readint(3);
            //printf("len %d:\n\t", len);
            if(len == 0)
            {

                break;
            }

            for(;;)
            {
                int v = readint(len);
                if(v == (1<<len) - 1)
                {
                    break;
                }
                //printf(" %d", v);
                putchar(code[len][v]);
            }
            //printf("\n");
        }
        printf("\n");
    }
}

char readchar()
{
    char ch;
    while(1)
    {
        ch = getchar();
        if(ch != '\n' && ch != '\r')
        {
            return ch;
        }
    }
}

int readint(int len)
{
    int n = 0;
    char ch;
    while(len--)
    {
        ch = readchar();
        n = (n<<1) + ch - '0';
    }
    return n;
}

int readcode()
{
    memset(code, 0, sizeof(code));

    char ch = readchar();
    if(ch == EOF)
    {
        return 0;
    }
    code[1][0] = ch;

    for(int i = 2; i < 8; i++)
    {
        //printf("%d (%d)\n", i, (1<<i) - 2);
       // printf("\t");
        for(int j = 0; j <= ((1<<i) - 2); j++)
        {
        //    printf("%d ", j);
            ch = getchar();
            if(ch == EOF)
            {
                return 0;
            }
            if(ch == '\n' || ch =='\r')
            {
                return 1;
            }
            code[i][j] = ch;
        }
        //printf("\n");
    }
    return 1;
}

void printcode()
{
    for(int i = 0; i < 8; i++)
    {
        printf("line %d:   ", i);
        for(int j = 0; j < 1<<8; j++)
        {
            putchar(code[i][j]);
        }
        putchar('\n');
    }
}




