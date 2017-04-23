#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;


char n2x[36];
int main(void)
{
    for(int i = 0; i < 36; i++)
    {
        if(i <=9)
        {
            n2x[i] = '0' + i;
        }
        else
        {
            n2x[i] = 'A' + i - 10;
        }
    
    }
    int a, p ;
    cin >> a >> p;

    vector<int> v;
    do
    {
        v.push_back(a % p);
        a /= p;
    }while(a != 0);

    for(int i = 0; i < v.size(); i++)
    {
        cout << n2x[v[v.size() - 1 - i]];
    }
    
    cout << endl;

}
