#include<cstdio>
#include<iostream>
#include<vector>
#include<string.h>
using namespace std;

int l[15];
void set(string a, int s);
int main(void)
{
    int n;
    while(cin >> n) 
    {
        while(n--)    
        {
            memset(l, -100, sizeof(l));

            string a, b, s;
            for(int i = 0; i < 3; i++)
            {
                cin >> a >> b >> s;
                if(s == "even")
                {
                    set(a, 0);
                    set(b, 0);
                }
                else if(s == "up")
                {
                    set(a, 1);
                    set(b, -1);
                }
                else if(s == "down")
                {
                    set(a, -1);
                    set(b, 1);
                }
            }

            for(int i = 0; i < 12; i++)
            {
                if(l[i] == 1)
                {
                    putchar('A' + i);
                    cout << " is the counterfeit coin and it is heavy." << endl;
                    break;
                }
                if(l[i] == -1)
                {
                    putchar('A' + i);
                    cout << " is the counterfeit coin and it is light."<< endl;;
                    break;
                }
            }
        
        }
    }

}

void set(string a, int s)
{
    for(int i = 0; i < a.size(); i++)
    {
        if(l[a[i] - 'A'] != 0) l[a[i] - 'A'] = s;
    }
}


