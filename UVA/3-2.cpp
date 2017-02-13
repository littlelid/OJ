#include<stdio.h>
#include<string.h>

int main(void)
{
    double C = 12.01;
    double H = 1.008;
    double O = 16.00;
    double N = 14.01;
    int n;
    scanf("%d", &n);

    char data[100];

    for(int i = 0; i < n; i++)
    {
        scanf("%s", data);
        double mass = 0;
        int len;
        len = strlen(data);

        int num = 0;
        for(int j = 0; j < len; j++)
        {

            if(data[j] == 'C')
            {



                if(data[j + 1] < 'A' && data[j + 1] != '\0')
                {

                    sscanf(data+j+1, "%d", &num);
                    mass += num * C;
                    //printf("add C * %d\n", num);
                    if(num >= 10)
                    {
                        j += 2;
                    }
                    else
                    {
                        j += 1;
                    }
                }
                else
                {
                    //printf("add C * 1\n");
                    mass += C;
                }
            }
            else if(data[j] == 'N')
            {

                if(data[j + 1] < 'A' && data[j + 1] != '\0')
                {
                    sscanf(data+j+1, "%d", &num);
                    mass += num * N;
                    //printf("add N * %d\n", num);
                    if(num >= 10)
                    {
                        j += 2;
                    }
                    else
                    {
                        j += 1;
                    }
                }
                else
                {
                    mass += N;
                    //printf("add N * 1\n");
                }
            }
            if(data[j] == 'O')
            {

                if(data[j + 1] < 'A' && data[j + 1] != '\0')
                {
                    sscanf(data+j+1, "%d", &num);
                    mass += num * O;
                    //printf("add O * %d\n", num);
                    if(num >= 10)
                    {
                        j += 2;
                    }
                    else
                    {
                        j += 1;
                    }
                }
                else
                {
                    mass += O;
                    //printf("add O * 1\n");
                }
            }
            if(data[j] == 'H')
            {

                if(data[j + 1] < 'A' && data[j + 1] != '\0')
                {
                    sscanf(data+j+1, "%d", &num);
                    mass += num * H;
                    //printf("add H * %d\n", num);
                    if(num >= 10)
                    {
                        j += 2;
                    }
                    else
                    {
                        j += 1;
                    }
                }
                else
                {
                    mass += H;
                    //printf("add H * 1\n");
                }
            }
        }
        printf("%.3f\n", mass);
    }
}

