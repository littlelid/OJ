#include<cstdio>
#include<iostream>
#include<vector>

using namespace std;
int num[35];
void flip(int *num, int k);

int main(void)
{
    int n;
    while(1)
    {
        cin >> n;
        if(!n) break;

        for(int i = 1; i <= n; i++) cin >> num[i];

        vector<int> ans;
        for(int i = n; i >= 2; i--)
        {
            int p = i;
            //cout << "p: " << p << endl;
            while(num[p] != i) p--;
            //cout << "p: " << p << endl;
            if(p != i)
            {
                if(p > 1)
                {
                    ans.push_back(p);
                    flip(num, p);
                }

                ans.push_back(i);
                flip(num, i);
            }
            //for(int i = 1; i <= n; i++) cout << num[i] <<' ';
            //cout << endl;
        }
        cout << ans.size();
        for(int i = 0; i < ans.size(); i++)
            cout << ' ' << ans[i];
        cout << endl;
    }
}


void flip(int *num, int k)
{
    int i = 1; 
    int j = k;
    int temp;

    while(i < j)
    {
        temp = num[i];
        num[i] = num[j];
        num[j] = temp;
        i++; j--;
    }

}
