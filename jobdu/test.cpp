#include<cstdio>
#include<iostream>
#include<string>
#include<queue>
using namespace std;
int main(void)
{
    string s;
    s.assign("wwg");
    cout << s << endl;
    string t;
    t.assign(s);
    t[0] = 'W';
    cout << t << endl;
    cout << s << endl;
}
