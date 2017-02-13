#include<cstdio>
#include<algorithm>
using namespace std;

int main(void)
{
    int n, q, num[10000];
    int kase = 0;
    while(1)
    {




        scanf("%d%d", &n, &q);
        if(n == 0 && q==0)
        {
            break;
        }
        for(int i = 0; i < n; i++)
        {
            scanf("%d", num + i);
        }
        sort(num, num + n);
        printf("CASE# %d:\n", ++kase);
        for(int i = 0; i < q; i++)
        {
            int x;
            scanf("%d", &x);
            int pos = lower_bound(num, num+n, x) - num;
            if(num[pos] == x)
            {
                printf("%d found at %d\n", x, pos + 1);

            }
            else
            {
                printf("%d not found\n", x);
            }
        }

    }
    return 0;
}
