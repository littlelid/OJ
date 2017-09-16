#include<cstdio>
#include<iostream>
#include<string>
#include<stack>
using namespace std;


struct node
{
    int i, j, k;
    node(int i, int j, int k):i(i),j(j),k(k){}
};


class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size() + s2.size() != s3.size()) return false;
        stack<node> s;
        int i = 0, j = 0;
        bool ans = true;
        int visit[300][300];
        memset(visit, 0, sizeof(visit));
        int cnt = 0;
        for(int k = 0; k < s3.size(); k++)
        {
            visit[i][j] = 1;
            //cout << i << ' ' << j << ' ' << k << endl;
            //cout << s1.size() - i + s2.size() - j << " " << s3.size() - k << endl;
            //cnt++;
            if(visit[i][j] == 0) 
            {   
                cnt++;
                cout << "\t***" << cnt << ' ' << s.size() << endl;   
                
            }
            bool flag1 = (i < s1.size() && s3[k] == s1[i]);
            bool flag2 = (j < s2.size() && s3[k] == s2[j]);
            if( flag1 && flag2 )
            {
                s.push(node(i, j, k));
                i++;
            }
            else if(flag1) i++;
            else if(flag2) j++;
            else{
                
                //d[i + 1][j] = 0;
                
                while( !s.empty() && visit[s.top().i][s.top().j + 1] == 1)
                {
                    //cout << "\tpop" << endl;
                    s.pop();
                }
                if(s.empty()) return false;
                else {
                    node n = s.top(); s.pop();
                    //cout << "\t" << visit[n.i][n.j + 1] << endl;
                    i = n.i; j = n.j; k = n.k;
                    j++;
                }
                
            }
            
        }   
        return ans;     
    }
};

int main(void)
{
    Solution s;
    string s1, s2, s3;
    //cin >> s1 >> s2 >> s3;
    //cout << s.isInterleave("aabcc", "dbbca", "aadbbbaccc") << endl;
    cout << s.isInterleave("abbc", "bda", "abdbbac") << endl;
    //cout << s.isInterleave(s1, s2, s3) << endl;
}