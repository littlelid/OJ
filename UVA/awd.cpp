#include<cstdio>
#include<iostream>
#include<set>
#include<map>
#include <algorithm>
using namespace std;

int main(void)
{
    map<string, string> d1, d2;
    string s1, s2;
    s1.push_back('a');s1.push_back('a');s1.push_back('a');
    s2.push_back('b');s2.push_back('b');s2.push_back('b');
    cout << s1 << endl;
    cout << s2 << endl;

    d1[s1] = s2;
    s1.clear(); s2.clear();
    cout << s1 << s2 << endl;
    cout << d1["aaa"];


}
