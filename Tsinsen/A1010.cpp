#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;


char n2x[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
int main(void)
{
    int a;
    cin >> a;
    vector<int> v;

    do
    {
        v.push_back(a % 16);
        a /= 16;
    }while(a != 0);

    for(int i = 0; i < v.size(); i++)
    {
        cout << n2x[v[v.size() - 1 - i]];
    }
    
    cout << endl;

}
