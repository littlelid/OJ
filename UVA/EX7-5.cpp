#include<iostream>
#include<cstdio>

using namespace std;

int dfs(int cur);
int n, l;
int  s[1000];
int cnt = 0;
int main(void)
{
        cnt = 0;
        cin >> n >> l;
        dfs(0);

}

int dfs(int cur)
{
    cnt++;
    if(cnt - 1 == n)
    {
        for(int i = 0; i < cur; i++)
        {
            printf("%c", 'A' + s[i]);
        }
        cout << endl;
        return 0;
    }

    for(int i = 0; i < l; i++)
    {
        s[cur] = i;
       int ok = 1;
       for(int j = 1; 2*j <= cur + 1; j++)
       {
            int not_equal = 0;
            for(int k = 0; k < j; k++)
            {
                cout << s[cur-k] << s[cur-k-j] << endl;
                if(s[cur-k] != s[cur-k-j]) {not_equal = 1; cout << "###" << endl;}
            }
            if(!not_equal)
            {   ok = 0; 
                break;
            }
       }
       if(ok) if(!dfs(cur+1)) return 0;
    }
    return 1;
}
