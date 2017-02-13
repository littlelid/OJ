#include<cstdio>
#include<iostream>
#include<map>
#include<sstream>
using namespace std;

int main(void)
{
    int T;
    cin >> T;
    getchar();
    while(T--)
    {
        string tree;
        map<long long, int> cnt;
        getline(cin, tree);
        
        //cout << tree << endl;
        
        int i = 0;
        int d = 0;
        int num_node = 0;
        while(1)
        {
            //cout << '\t' << i << endl;    
            if(i >= tree.size()) break;
            if(tree[i] == ',') { i++; continue;}
            if(tree[i] == '[') { i++; d++; continue;}
            if(tree[i] == ']') { i++; d--; continue;}
            
            long long num = 0;
            
            while(tree[i] >= '0' && tree[i] <= '9')
            {
                num += tree[i] - '0';
                num *= 10;
                i++;
            }
            num_node++;
            num /= 10;
            //cout << "\t" << num << endl;
            if(!cnt.count(num << d)) cnt[num << d] = 0;
            cnt[num << d]++;
        }
        int maxn = 0;
        map<long long, int>::iterator it;
        for(it = cnt.begin(); it != cnt.end(); it++)
        {
            if(it->second > maxn) maxn = it->second; 
            //cout << "(" << it->first << "," << it->second << ")" << endl;
        }

        cout << num_node - maxn << endl;
    }

    
}