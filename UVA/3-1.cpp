#include<stdio.h>
#include<string.h>

int main(void)
{
    int n;
    scanf("%d", &n);

    char data[100];

    for(int i = 0; i < n; i++)
    {

        scanf("%s", data);
        int scores = 0;
        int len;
        len = strlen(data);
        int s = 1;
        for(int j = 0; j < len; j++)
        {

            if(data[j] == 'O')
            {
                scores += s;
                s += 1;
            }
            else{
                s = 1;
            }
        }
        printf("%d\n", scores);
    }
}
