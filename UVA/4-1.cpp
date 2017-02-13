#include<stdio.h>
#include<string.h>
#include<math.h>
#define TEST 1
typedef struct{
    char type;
    int x;
    int y;
} Cheese;

Cheese black;
Cheese redcheeses[10];
int is_eat[10];
int num_cheese;

void printboard();
int readboard();

int black_can_move(int dx, int dy);

int abs(int x);
int A_between_BC(int A, int B, int C);
int num_intermedia(int i, Cheese local_black);
int exist_cheese(int x, int y);
int general_can_eat(int dx, int dy); //G
int chariot_can_eat(int dx, int dy);  //R
int horse_can_eat(int dx, int dy);    //H
int cannon_can_eat(int dx, int dy);   //C
int is_in_danger(int dx, int dy);

int eat_cheese(int x, int y);

int main(void)
{
    while(readboard())
    {

        if(general_can_eat(0, 0))
        {
            printf("NO\n");
        }
        else
        {
            if(is_in_danger(0, 0) == 0)
            {
                printf("NO\n");
            }
            else
            {
                if(TEST) printf("IN DANGER; try to move...\n");
                int can_escape = 0;

                if(black_can_move(1, 0))
                {
                    if(TEST) printf("MOVE(1, 0)\n");
                    int new_x = black.x + 1;
                    int new_y = black.y + 0;
                    int pos = eat_cheese(new_x, new_y);
                    if(is_in_danger(1, 0) == 0)
                    {
                        if(TEST) printf("\t success\n");
                        can_escape = 1;
                    }
                    if(pos != -1)
                    {
                        is_eat[pos] = 0;
                    }

                }

                if(black_can_move(-1, 0))
                {
                    if(TEST) printf("MOVE(-1, 0)\n");
                    int new_x = black.x - 1;
                    int new_y = black.y + 0;
                    int pos = eat_cheese(new_x, new_y);
                    if(is_in_danger(-1, 0) == 0)
                    {
                        if(TEST) printf("\t success\n");
                        can_escape = 1;
                    }

                    if(pos != -1)
                    {
                        is_eat[pos] = 0;
                    }
                }

                if(black_can_move(0, 1))
                {
                    if(TEST) printf("MOVE(0, 1)\n");
                    int new_x = black.x + 0;
                    int new_y = black.y + 1;
                    int pos = eat_cheese(new_x, new_y);
                    if(is_in_danger(0, 1) == 0)
                    {
                        if(TEST) printf("\t success\n");
                        can_escape = 1;
                    }

                    if(pos != -1)
                    {
                        is_eat[pos] = 0;
                    }
                }

                if(black_can_move(0, -1))
                {
                    if(TEST) printf("MOVE(0, -1)\n");
                    int new_x = black.x + 0;
                    int new_y = black.y - 1;
                    int pos = eat_cheese(new_x, new_y);
                    if(is_in_danger(0, -1) == 0)
                    {
                        if(TEST) printf("\t success\n");
                        can_escape = 1;
                    }

                    if(pos != -1)
                    {
                        is_eat[pos] = 0;
                    }
                }
                if(can_escape)
                {
                    if(TEST) printf("here can_escape\n");
                    printf("NO\n");
                }
                else
                {
                    if(TEST) printf("here canT_escape\n");
                    printf("YES\n");
                }
            }
        }
    }
    printf("\n");
}

int readboard()
{
    memset(redcheeses, 0, sizeof(redcheeses));
    memset(is_eat, 0, sizeof(is_eat));
    num_cheese = 0;
    black.type = 'B';

    int n, x, y;
    scanf("%d%d%d", &n, &x, &y);

    if(n==0 && x==0 && y==0)
    {
        if(TEST) printf("END\n");
        return 0;
    }
    else
    {
        num_cheese = n;
        black.x = x;
        black.y = y;

        num_cheese = n;
        //printf("readboard--- n:%d\n", n);
        char ch;
        int xx, yy;
        for(int i = 0; i < n; i++)
        {
            //printf("readboard--- i:%d\n", i);
            getchar();
            scanf("%c %d %d", &ch, &xx, &yy);

            redcheeses[i].type = ch;
            redcheeses[i].x = xx;
            redcheeses[i].y = yy;
        }
        //printf("readboard...end\n");
        return 1;
    }
    return 1;
}


void printboard()
{
    printf("printboard...begin\n");
    printf("blakc (%d, %d)\n", black.x, black.y);
    for(int i = 0; i < num_cheese; i++)
    {
        printf("%c (%d, %d)\n", redcheeses[i].type, redcheeses[i].x, redcheeses[i].y);
    }
    printf("printboard...end\n");
}

int black_can_move(int dx, int dy)
{
    if(A_between_BC(black.x + dx, 0, 4) && A_between_BC(black.y + dy, 3, 7))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int abs(int x)
{
    return x>0?x:-x;
}
int A_between_BC(int A, int B, int C)
{
    if(A < B && A > C)
    {
        return 1;
    }
    if(A > B && A < C)
    {
        return 1;
    }
    return 0;
}

int num_intermedia(int i, Cheese local_black)
{
    int num = 0;
    if(redcheeses[i].x == local_black.x)
    {
        for(int j = 0; j < num_cheese; j++)
        {
            if(i != j && redcheeses[j].x == local_black.x && A_between_BC(redcheeses[j].y, redcheeses[i].y, local_black.y))
            {
                num++;
            }
        }

    }
    if(redcheeses[i].y == local_black.y)
    {
        for(int j = 0; j < num_cheese; j++)
        {
            if(i != j && is_eat[i] == 0 && redcheeses[j].y == local_black.y && A_between_BC(redcheeses[j].x, redcheeses[i].x, local_black.x))
            {
                num++;
            }
        }

    }

    return num;
}

int exist_cheese(int x, int y)
{
    for(int i = 0; i < num_cheese; i++)
    {
        if(redcheeses[i].x == x && redcheeses[i].y == y)
        {
            return 1;
        }
    }
    if(black.x == x && black.y == y)
    {
        return 1;
    }
    return 0;
}

int general_can_eat(int dx, int dy)//G
{
    Cheese temp_black;
    temp_black.type = black.type;
    temp_black.x = black.x + dx;
    temp_black.y = black.y + dy;

    for(int i = 0; i < num_cheese; i++)
    {
        if(redcheeses[i].type == 'G' && is_eat[i] == 0)
        {
            if(redcheeses[i].y == temp_black.y)
            {

                if(num_intermedia(i, temp_black) == 0)
                {
                    if(TEST) printf("\tGeneral crash\n");
                    return 1;
                }

            }

        }
    }
    if(TEST) printf("\tCAN'T eat  General \n");
    return 0;
}

int chariot_can_eat(int dx, int dy)  //R
{
    Cheese temp_black;
    temp_black.type = black.type;
    temp_black.x = black.x + dx;
    temp_black.y = black.y + dy;

    for(int i = 0; i < num_cheese; i++)
    {
        if(redcheeses[i].type == 'R' && is_eat[i] == 0)
        {
            if(redcheeses[i].x == temp_black.x || redcheeses[i].y == temp_black.y)
            {
                if(num_intermedia(i, temp_black) == 0)
                {
                    if(TEST) printf("\teat by chariot\n");
                    return 1;
                }
            }
        }
    }
    if(TEST) printf("\tCANT'T eat by chariot\n");
    return 0;
}

int horse_can_eat(int dx, int dy)   //H
{
    Cheese temp_black;
    temp_black.type = black.type;
    temp_black.x = black.x + dx;
    temp_black.y = black.y + dy;

    for(int i = 0; i < num_cheese; i++)
    {
        if(redcheeses[i].type == 'H' && is_eat[i] == 0)
        {
            int delta_x = temp_black.x - redcheeses[i].x;
            int delta_y = temp_black.y - redcheeses[i].y;

            if(abs(delta_x) == 2 && abs(delta_y) == 1)
            {
                if(delta_x > 0)
                {
                    if(exist_cheese(redcheeses[i].x + 1, redcheeses[i].y) == 0)
                    {
                        if(TEST) printf("\teat by horse: %d %d (1)\n", delta_x, delta_y);
                        return 1;
                    }
                }

                if(delta_x < 0)
                {
                    if(exist_cheese(redcheeses[i].x - 1, redcheeses[i].y) == 0)
                    {
                        if(TEST) printf("\teat by horse: %d %d(2)\n", delta_x, delta_y);
                        return 1;
                    }
                }

            }
            if(abs(delta_y) == 2 && abs(delta_x) == 1)
            {
                if(delta_y > 0)
                {
                    if(exist_cheese(redcheeses[i].x, redcheeses[i].y + 1) == 0)
                    {
                        if(TEST) printf("\teat by horse: %d %d(3)\n", delta_x, delta_y);
                        return 1;
                    }
                }

                if(delta_y < 0)
                {
                    if(exist_cheese(redcheeses[i].x, redcheeses[i].y - 1) == 0)
                    {
                        if(TEST) printf("\teat by horse: %d %d(4)\n", delta_x, delta_y);
                        return 1;
                    }
                }
            }
        }
    }
    if(TEST) printf("\tCANT eat by horse\n");
    return 0;

}
int cannon_can_eat(int dx, int dy)   //C
{
    Cheese temp_black;
    temp_black.type = black.type;
    temp_black.x = black.x + dx;
    temp_black.y = black.y + dy;

    for(int i = 0; i < num_cheese; i++)
    {
        if(redcheeses[i].type == 'C' && is_eat[i] == 0)
        {
            if(redcheeses[i].x == temp_black.x || redcheeses[i].y == temp_black.y)
            {
                if(num_intermedia(i, temp_black) == 1)
                {
                    if(TEST) printf("\teat by cannon\n");
                    return 1;
                }
            }
        }
    }
    return 0;
}
int is_in_danger(int dx, int dy)
{
    int a = general_can_eat(dx, dy);
    int b = chariot_can_eat(dx, dy);
    int c = horse_can_eat(dx, dy);
    int d = cannon_can_eat(dx, dy);
    if(TEST) printf("\t is in danger(%d, %d): %d %d %d %d\n", dx, dy, a, b, c, d);
    return a + b + c + d;
}

int eat_cheese(int x, int y)
{
    for(int i = 0; i < num_cheese; i++)
    {
        if(redcheeses[i].x == x && redcheeses[i].y == y)
        {
            is_eat[i] = 1;
            return i;
        }
    }

    return -1;
}

