#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;


vector<int> parse(int a);
int check(vector<int> a, vector<int> b);

int main(void)
{
    int n;
    while(cin >> n)
    {
        while(n--)
        {
            int a, b;
            cin >> a >> b;
            vector<int> bin1, bin2;
            bin1 = parse(a);
            bin2 = parse(b);

            int ans = check(bin1, bin2);
            if(ans) cout << "YES" << endl;
            else    cout << "NO" << endl;
        
        }
    
    
    }


}

vector<int> parse(int a)
{
    vector<int> bin;
    while(a)
    {
        bin.push_back(a % 2);
        a /= 2;
    }
    while(bin.size() < 16) bin.push_back(0);
    return bin;
}

int check(vector<int> a, vector<int> b)
{

    int flag;
    for(int i = 0; i < 16; i++)
    {
        flag = 1;
        for(int j = 0; j < 16; j++)
        {
            if(b[j] != a[(i + j) % 16]) 
            {
                flag = 0;
                break;
            }
        }
        if(flag) break;
    }
    return flag;
}
