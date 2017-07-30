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
int dfs(int prem[], int depth);

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
        int res = dfs(prem, 0);
        if(res)
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
    /*
    for(int i = cur; i <= 20; i += cur)
    {
        prem[i] = 0;
        for(int j = 2; j <= 20; j++)
        {
            if(!prem[j] && i + j <= 20 )
                prem[i + j] = 0;
        }
    }
    */
    prem[cur] = 0;
    for(int i = 2; i + cur <= 20; i++)
    {
        if(prem[i] == 0)
        {
            prem[cur + i] = 0; 
        }
    }
}

int dfs(int prem[], int depth)
{
    int code = encode(prem);
    if(dp[code] >= 0) return dp[code];

    int prem_bak[22];

    memcpy(prem_bak, prem, sizeof(prem_bak));

    /*
    cout << "\torg:";
    for(int i = 2; i <= 20; i++) if(prem[i]) cout << ' ' << i;
    cout << endl;
    cout << "\tbak:";
    for(int i = 2; i <= 20; i++) if(prem_bak[i]) cout << ' ' << i;
    cout << endl;
    */


    int res = -1;
    int flag = 0;
    for(int i = 2; i <= 20; i++)
    {
        if(prem[i])
        {
            /*
            if(depth == 0 )
            {
                cout << i << endl;

                cout << "\tbefore set";
                for(int i = 2; i <= 20; i++) if(prem[i]) cout << ' ' << i;
                cout << endl;
            }
            */
            set(prem, i);
            /*
            if(depth == 0)
            { 
                cout << "\tafter set";
                for(int i = 2; i <= 20; i++) if(prem[i]) cout << ' ' << i;
                cout << endl;
            }
            */
            res = dfs(prem, depth + 1);
            if(res == 0) 
            {
                if(depth == 0)
                {
                    ans[i] = 1;
                    //cout << '\t' <<  i  << endl;
                }

                flag = 1;
            }
            
            memcpy(prem, prem_bak, sizeof(prem_bak));
        
        }
    }

    dp[code] = flag;
    return flag;

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


