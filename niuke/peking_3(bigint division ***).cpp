#include<cstdio>
#include<iostream>
#include <algorithm>
#include<vector>
#include<string.h>
#include<stack>
using namespace std;


int main(void)
{
    
    
    int M, N;
   
    while(cin >> M)
    { 
        cin >> N;
        getchar();
    
        string X;
        cin >> X;
    
    vector<int > org(X.size(), 0);
    
    for(int i = 0; i < X.size(); i++)
    {
        char ch = X[i];
        if(ch >= '0' && ch <= '9') org[i] = (ch - '0');
        else                       org[i] = (10 + (ch - 'A'));
    }
    
    stack<char> ans;
    for(int i = 0; i < org.size(); org[i]?0:++i)
    {
        int c = 0;
        for(int j = i; j < org.size(); j++)
        {
            org[j] += c * M;
            c = org[j] % N;
            org[j] /= N;
        }
        ans.push(c > 9 ? 'a' + c - 10 : '0' + c);

    }

    for(; ans.top() == '0'; ans.pop());

    for(; ans.size(); cout << ans.top(), ans.pop());
    cout << endl;

    }
}