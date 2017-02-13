#include<iostream>
#include<vector>
#include<string>
#include<cstdio>

using namespace std;

struct node
{
    int next;
    int prio;
};

int main(void)
{
    int n, m;
    int kase = 0;
    while(cin >> n >> m)
    {
        kase++;
        //cout << kase << "!!!" << endl;

        int rev = 0;
        node nodes[n+5];
        for(int i = 0; i <= n + 1; i++)
        {
            nodes[i].prio = i - 1;
            nodes[i].next = i + 1;
        }
        int head = 0;
        int tail = n + 1;

        //cout << n << m;
        while(m--)
        {

            int o, x, y;
            cin >> o;
            if(o == 4)
            {
                if(rev == 0) rev = 1;
                else rev = 0;
                //cout << "op = " << o << endl;
            }
            else
            {
                cin >> x >> y;
                //cout << "op = " << o << ":" << x << " " << y << endl;
                if((rev == 0 &&o == 1) ||  (rev == 1 &&o == 2))
                {
                    int p = nodes[x].prio;
                    int n = nodes[x].next;
                    nodes[p].next = n;
                    nodes[n].prio = p;

                    int p_y = nodes[y].prio;
                    nodes[x].next = y;
                    nodes[x].prio = p_y;
                    nodes[p_y].next = x;
                    nodes[y].prio = x;

                }
                else if((rev == 0 &&o == 2) ||  (rev == 1 &&o == 1))
                {
                    int p = nodes[x].prio;
                    int n = nodes[x].next;
                    nodes[p].next = n;
                    nodes[n].prio = p;

                    int n_y = nodes[y].next;
                    nodes[x].next = n_y;
                    nodes[x].prio = y;
                    nodes[n_y].prio = x;
                    nodes[y].next = x;
                }
                else if(o == 3)
                {

                    int p_x = nodes[x].prio;
                    int n_x = nodes[x].next;

                    int p_y = nodes[y].prio;
                    int n_y = nodes[y].next;

                    if(p_y == x)
                    {
                        nodes[x].next = n_y;
                        nodes[x].prio = y;

                        nodes[y].next = x;
                        nodes[y].prio = p_x;

                        nodes[p_x].next = y;
                        nodes[n_y].prio = x;
                    }
                    else if(p_x == y)
                    {
                        nodes[y].next = n_x;
                        nodes[y].prio = x;

                        nodes[x].next = y;
                        nodes[x].prio = p_y;

                        nodes[p_y].next = x;
                        nodes[n_x].prio = y;
                    }
                    else
                    {
                        nodes[y].next = n_x;
                        nodes[y].prio = p_x;

                        nodes[x].next = n_y;
                        nodes[x].prio = p_y;

                        nodes[p_x].next = y;
                        nodes[n_y].prio = x;

                        nodes[n_x].prio = y;
                        nodes[p_y].next = x;
                    }
                }
            }
            int index;

            if(rev == 0) index = nodes[head].next;
            else index = nodes[tail].prio;

            /*while(index != tail && index != head)
            for(int i = 1; i <= n; i++)
            {
                cout << index << endl;
                cout << "\t" << i <<": " << "p-" << nodes[i].prio << ",  n- " << nodes[i].next << endl;
                if(rev == 0) index = nodes[index].next;
                else index = nodes[index].prio;
            }*/
        }


        long long  sum = 0;

        int index;

        if(rev == 0) index = nodes[head].next;
        else index = nodes[tail].prio;

        //while(index != tail && index != head)
        for(int i = 1; i <= n; i++)
        {
            //cout << index << endl;
            if(i % 2 != 0)
            {

                sum += index;
            }


            if(rev == 0) index = nodes[index].next;
            else index = nodes[index].prio;
        }



        printf("Case %d: %lld\n", kase, sum);
    }

}


