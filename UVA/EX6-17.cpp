#include<cstdio>
#include<vector>
#include<iostream>
#include<string.h>
using namespace std;

char G[205][205];
vector<char>  ans;

int islabel(char ch);
void read();
void dfs(int r, int c);
void print();
int main(void)
{
    int T;
    cin >> T;
    getchar();
    while(T--)
    {
        read();
        int cc = 1;
        while(!islabel(G[1][cc])) cc++;
        //cout << "!!!!" << G[1][cc]<< endl;
        ans.clear();
        ans.push_back('(');
        if(cc < 202) dfs(1, cc);
        ans.push_back(')');

        print();
    }

}
int islabel(char ch)
{
    if(ch == '-' || ch == '|' || ch == ' ' || ch == '#') return 0;
    else return 1;

}

void read()
{
    memset(G, ' ', sizeof(G));
    string line;
    int r = 1;
    while(1)
    {
        getline(cin, line);
        //cout << line << endl;
        if(line == "#") break;
        for(int c = 0; c < line.size(); c++)
        {
            G[r][c + 1] = line[c];
            //cout << "(" << r << "," << c + 1 << ")" << endl;
        }
        r++; //cout << "&&&" << r << endl;
    }
    /*for(int i = 1; i < r; i++)
    {
        for(int j = 1; j < 30; j++)
        {
            cout << G[i][j];
        }
        cout << endl;
    }
    */
}

void dfs(int r, int c)
{
    //cout << c << endl;
    ans.push_back(G[r][c]);

    ans.push_back('(');

    if(G[r+1][c] == '|')
    {
        int c_l = c - 1;
        int c_r = c + 1;
        while((G[r+2][c_l]) == '-') c_l--; //&& !islabel()  && G[r][c_l] == ' '
        while((G[r+2][c_r]) == '-') c_r++;
        //cout << '\t' << c_l << "***,***" << c_r << endl;
        for(int i = c_l + 1; i < c_r; i++)
        {
            if(islabel(G[r+3][i])) dfs(r+3, i);
        }
    }

    ans.push_back(')');

}

void print()
{
    int len = ans.size();
    for(int i = 0; i < len; i++)
    {
        cout << ans[i];
    }
    cout << endl;
}


