#include<cstdio>
#include<iostream>
#include<string.h>
using namespace std;
char map[3005][3005];
char tmp[3005][3005];

void draw(char map[][3005], char tmp[][3005], int x, int y, int step, int N);
int main(void)
{
    int N;
    char ch;
    while(1)
    {
        cin >> N;
        //cout << N << endl;
        getchar();
        if(N == 0) break;

        memset(map, ' ', sizeof(map));
        memset(tmp, ' ', sizeof(tmp));

        for(int i = 0; i < N; i++)
        {
            for(int j = 0; j < N; j++)
            {
                ch = getchar();
                tmp[i][j] = ch;
            }
            getchar();
        }
        //for(int i = 0; i < N; i++)
        //{
        //    for(int j = 0; j < N; j++)
        //        cout << tmp[i][j];
        //    cout << endl;
        //}

        int level;
        cin >> level;
        int step = 1;
        for(int i = 0; i < level - 1; i++) step *= N;
        //cout << step << ' ' << N << endl;
        draw(map, tmp, 0, 0, step, N);
        for(int i = 0; i < step*N; i++)
        {
            for(int j = 0; j < step*N; j++)   
            {
                cout << map[i][j];
            }
            cout << endl;
        }
    }
}

void draw(char map[][3005], char tmp[][3005], int x, int y, int step, int N)
{
    for(int i = 0; i < N; i++)
    {
        int row = x + i * step;
        for(int j = 0; j < N; j++)
        {
            int col = y + j*step;
            if(step == 1)
            {
                map[row][col] = tmp[i][j];
                //cout << row << ' ' << col << ' ' << tmp[i][j] << endl;
            }
            else
            {
                if(tmp[i][j] != ' ')
                    draw(map, tmp, row, col, step / N, N);

            }
        }

    
    }
   

}
