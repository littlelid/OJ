#include<cstdio>
#include<iostream>
#include<string.h>

using namespace std;

int MAX = 1 << 21;
int dp[1 << 21];
int ans[22];
//  dp = 1: win 
//  dp = 0; lose
void set(int prem[], int cur);
int encode(int prem[]);
int dfs(int prem[]);

int main(void)
{
    int n;
    int kase = 0;
    memset(dp, -1, sizeof(dp));
    dp[0] = 0;
    while(1)
    {
        cin >> n;
        if(n == 0) break;
        kase++;

        int prem[22];
        int num;
        for(int i = 1; i <= 20; i++) {prem[i] = 0; ans[i] = 0; }
        for(int i = 1; i <= n; i++)
        {
            cin >> num;
            prem[num] = 1;
        }
        cout << "Test Case #" << kase << endl;
        int flag = 0;
        int prem_bak[22];
        memcpy(prem_bak, prem, 22*sizeof(int));
        for(int i = 2; i <= 20; i++)
        {
            if(prem[i]) 
            {

                set(prem, i);


                if(!dfs(prem))
                {
                    flag = 1;
                    ans[i] = 1;
                }
                memcpy(prem, prem_bak, 22*sizeof(int));
            }
        }

        if(flag)
        {
            cout << "The winning moves are:";
            for(int i = 2; i <= 20; i++)
            {
                if(ans[i]) cout << ' ' << i;
            }
            cout << endl;
        }
        else
        {
            cout << "There's no winning move." << endl;
        }
        cout << endl;
        
    
    }
}

void set(int prem[], int cur)
{
    prem[cur] = 0;
    for(int i = 2; i + cur <= 20; i++)
    {
        if(prem[i] == 0)
        {
            prem[cur + i] = 0; 
        }
    }
}

int dfs(int prem[])
{

    int code = encode(prem);
    if(dp[code] >= 0) return dp[code];
    int prem_bak[22];
    memcpy(prem_bak, prem, 22*sizeof(int));

    //set(prem_bak, cur);

    
    for(int i = 2; i <= 20; i++)
    {
        if(prem[i])
        {
            set(prem, i);
            if(!dfs(prem))
            {
                dp[code] = 1;
                return 1;
            }
            memcpy(prem, prem_bak, 22*sizeof(int));

        }
    }

    dp[code] = 0;
    return 0;
}

int encode(int prem[])
{
    int num = 0;
    for(int i = 2; i <= 20; i++)
    {
        num += prem[i];
        num = num << 1;
    }
    num = num >> 1;
    return num;
}


