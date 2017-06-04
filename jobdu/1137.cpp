#include<cstdio>
#include<iostream>
#include<string>
#include<vector>
#include<sstream>
#include<algorithm>
using namespace std;

vector<int> add(vector<int> a, vector<int> b, int c);
int main(void)
{
    int n;
    cin >> n;
    getchar();

    while(n --)
    {
            string num1, num2;
            getline(cin, num1);
            getline(cin, num2);
            int doc_loc1 = 0;
            int doc_loc2 = 0;
            while(num1[doc_loc1] != '.') doc_loc1++;
            while(num2[doc_loc2] != '.') doc_loc2++;
            
            int fac1_len = num1.size() - doc_loc1;
            int fac2_len = num2.size() - doc_loc2;

            if(fac1_len > fac2_len)
            {
                for(int i = 0; i < fac1_len - fac2_len; i++)
                    num2.push_back('0');
            }
            else
            {
                for(int i = 0; i < fac2_len - fac1_len; i++)
                    num1.push_back('0');
            }

            vector<int> a, b;
            
            int temp1 = num1.size() - 1;
            int temp2 = num2.size() - 1;
            while(temp1 >= 0 || temp2 >= 0)
            {
                if(temp1 == doc_loc1) 
                    temp1--;
                if(temp2 == doc_loc2) 
                    temp2--;

                if(temp1 >= 0) a.push_back(num1[temp1] - '0') ;
                else           a.push_back(0) ;

                if(temp2 >= 0) b.push_back(num2[temp2] - '0') ;
                else           b.push_back(0) ;
                temp1--;
                temp2--;
            }
            vector<int> ans = add(a, b, 0);
            int fac_len = (fac1_len > fac2_len) ? fac1_len : fac2_len;
            //cout << fac_len << ' ' << ans.size() << endl;

            int zero_loc = 0;
            while(ans[zero_loc] == 0 && zero_loc < ans.size() ) zero_loc++;
            for(int i = ans.size() - 1; i >= zero_loc; i --)
            {
                if(i ==  fac_len - 2 ) cout << '.';
                cout << ans[i];
            }
            cout << endl;
            getchar();
            
    }

}
vector<int> add(vector<int> a, vector<int> b, int c)
{
    vector<int > res;
    int temp;
    for(int i = 0; i < a.size(); i++)
    {
        temp = a[i] + b[i] + c;
        res.push_back(temp % 10);
        c = temp / 10;
    }

    if(c) res.push_back(1);

    return res;
}







