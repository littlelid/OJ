#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

void dfs(int len, vector<int> &cont, int cur, vector<char> s);
int cnt_4;
int cnt_1;
int cnt = 0;
int main(void)
{
    vector<int>  conts;

    for(int i = 2; i <= 8; i+=2)
    {
        vector<char> s;
        for(int i  = 0; i < 8; i++)
            s.push_back('0');
        cnt_4 = i / 2;
        cnt_1 = i / 2;
        dfs(i, conts, 0, s);

        
    }
    sort(conts.begin(), conts.end());
    
    //dfs(8, cont, 0, s);
    for(int i = 0; i < conts.size(); i++)
        cout << conts[i] << endl;
    cout << cnt << endl;
}


void dfs(int len, vector<int> &cont, int cur, vector<char> s)
{
    cnt += 1;
    //cout << cur << endl;
    if(cur == len && cnt_4 == cnt_1)
    {
        int t = 0;  
        for(int i = 0; i < len; i++)
        {
            t += s[i] - '0';
            t *= 10;
            //cout << s[i];
        }
        //cout <<endl;
        t /= 10;
        //cout << t << endl;
        cont.push_back(t);
    }

    if(cnt_4 >0) 
    {
        cnt_4 -= 1;
        s[cur] = '4';
        dfs(len, cont, cur + 1, s);
        cnt_4 += 1;
    }

    if(cnt_1 >0) 
    {
        cnt_1 -= 1;
        s[cur] = '1';
        dfs(len, cont, cur + 1, s);
        cnt_1 += 1;
    }

    return;

}