#include<cstdio>
#include<iostream>
#include<string>
using namespace std;

int main(void)
{
    string s[105];
    int n;
    while(cin >> n)
    {
        for(int i = 0; i < 105; i++) s[i] = "wangweiguo";
        for(int i = 0; i < n; i++)
        {
            string t;
            int w;
            cin >> w >> t;
            s[w] = t;
        }
    
        for(int i = 104; i >= 0; i--)
        {
            if (s[i] != "wangweiguo") cout << s[i] << endl;
        }
    }
    

}
