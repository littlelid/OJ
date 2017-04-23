#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<string.h>

using namespace std;

int next_[1000005];

void generate_next(string pattern);

int main(void)
{
    int T;
    cin >> T;

    while(T--)
    {
        memset(next_, -1, sizeof(next_));
        string A, B;
        cin >> A >> B;
        
        generate_next(B);

        //for(int i = 0; i < B.size(); i++) cout << next_[i] << ' ';
        //cout << endl;

        int i = 0; 
        int j = 0;
        vector<int> ans;

        while(1)
        {
            while(i < A.size() && j < B.size() && A[i] == B[j]) i++,j++;

            if(j  >= B.size()) ans.push_back(i - B.size());
            if(i  >= A.size()) break;
            if(j == 0) {i++; continue;}

            j = next_[j - 1];
        }
        if(ans.size() == 0) 
            cout << "Not Found" << endl << endl;
        else
        {
            cout << ans.size() << endl;
            for(int i = 0; i < ans.size(); i++)
            {
                if(!i) cout << ans[i] + 1;
                else   cout << ' ' << ans[i] + 1;
            }
            cout << endl << endl;
        }
    
    }


}
void generate_next(string pattern)
{
    int j = 0;
    next_[j] = 0;
    for(int i = 1; i < pattern.size(); i++)
    {
        while(pattern[i] != pattern[j] && j != 0) { j = next_[j-1];}
        if(pattern[i] == pattern[j]) 
        {
            next_[i] = j + 1;
            j++; 
        }
        else
        {
            next_[i] = j;
        }
    }

}
