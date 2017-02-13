#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;

int main(void)
{
    int n;
    int kase = 0;
    //int first = 1;
    while(1)
    {
        
        cin >> n;
        if(n == 0) break;
        
        
        
        int ord[n];
        string t;
        for(int i = 0; i < n; i++)
        {
            cin >> t;
            //cout << t << " ";
            ord[i] = t[1] - '1'; 
           // cout << ord[i] << " " ;
        }
        //cout << endl;

        string tree;
        cin >> tree;
        
        //cout << "TREE: " << tree << endl; 
        
        int T;
        cin >> T;
        vector<char> ans;
        while(T--)
        {
            int pos = 0;
            string q;
            cin >> q;
            for(int i = 0; i < q.size(); i++)
            {
                pos += q[ord[i]] - '0';
                pos *= 2;
            }
            pos /= 2;
            //cout << "pos: " << pos << " " << tree[pos] - '0' << endl;
       
            ans.push_back(tree[pos]);
        }
        kase++;

        cout << "S-Tree #" << kase << ":" << endl;
        for(int i = 0; i < ans.size(); i++)
        {
            
            cout << ans[i];
        }
        cout << endl << endl;
    }
}