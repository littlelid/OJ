#include<cstdio>
#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main(void)
{
    int a, b, c;
    while(cin >> a >> b >> c)
    {
        vector<string> ans;
        int remain = 0;
        if(c == b)
            ans.push_back("fill B");
        else
        {
            while(1)
            {
                if(remain == c) break;
                remain += a;
                ans.push_back("fill A");
                ans.push_back("pour A B");

                if(remain == c) break;
                //cout << remain  << endl;
                if(remain >= b)
                {
                    ans.push_back("empty B");
                    remain -= b;

                    if(remain) ans.push_back("pour A B");
                }                
            }
        }

        for(int i = 0; i < ans.size(); i++)
            cout << ans[i] << endl;
        cout << "success" << endl;
    
    }

}
