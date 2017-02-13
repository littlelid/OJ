#include<cstdio>
#include<iostream>
#include<stack>
using namespace std;

int main(void)
{
    int T;    
    cin >> T;
    getchar();
    

    while(T--)
    {
        
        stack<char> s;
        char ch;
        ch = getchar();
        
        while(ch != '\n')
        {
            
            if(s.size() && ((ch == ')' && s.top() == '(') || (ch == ']' && s.top() == '[')) )
            {
                s.pop();
            
            }
            else
            {
                s.push(ch);
            
            }
            ch = getchar();
            
        }
        if(s.size()) cout << "No" << endl;
        else cout << "Yes" << endl;

        
    } 
}