#include<iostream>
#include<cstdio>
#include<string.h>
using namespace std;

int pic0[1024 + 5];
int pic1[1024 + 5];

void parse(int pic, int start, int len);
void smear(int pic, int start, int len, int color);

int main(void)
{
    int T;
    cin >> T;
    getchar();
    while(T--)
    {
        memset(pic0, 0, sizeof(pic0));
        memset(pic1, 0, sizeof(pic1));

        parse(0, 0, 1024);
        getchar();
        parse(1, 0, 1024);
        getchar();

        int sum = 0;
        for(int i = 0; i < 1024; i++)
        {
            if(pic0[i] || pic1[i])
            {
                sum++;
            }
        }
        cout << "There are " << sum <<" black pixels." << endl;
    }
}

void parse(int pic, int start, int len)
{
    char ch;
    cin >> ch;


    if(ch == 'f')
    {
        smear(pic, start, len, 1);
        return;
    }
    if(ch == 'e')
    {
        smear(pic, start, len, 0);
        return;
    }
    int sub_len = len / 4;
    parse(pic, start, sub_len);
    parse(pic, start + sub_len, sub_len);
    parse(pic, start + 2 * sub_len, sub_len);
    parse(pic, start + 3 * sub_len, sub_len);
}

void smear(int pic, int start, int len, int color)
{
    for(int i = start; i < start + len; i++)
    {
        if(pic == 0) pic0[i] = color;
        else         pic1[i] = color;
    }
}
