#include<cstdio>
#include<iostream>
#include<string>
#include<stack>
#include<string.h>
using namespace std;

int main(void)
{
    string s;
    while(cin >>s)
    {
        stack<char> t;
        int mark[s.size()];
        memset(mark, 0, sizeof(mark));
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == '(')
                t.push(i);
            else if(s[i] == ')')
            {
                if(!t.size()) mark[i] = 1;
                else t.pop(); 
            }
        }
        
        while(t.size())
        {
            mark[t.top()] = -1;
            t.pop();
        }
        cout << s << endl;
        for(int i = 0; i < s.size(); i++)
        {
            if(mark[i] == 0) cout << ' ';
            else if(mark[i] == 1) cout << '?';
            else if(mark[i] == -1) cout << '$';
        }
        cout << endl;

        
    }


}
