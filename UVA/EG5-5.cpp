#include<iostream>
#include<vector>
#include<stack>
#include<map>
#include<string>
#include<set>
#include<algorithm>
using namespace std;

typedef set<int> Set;
map<Set, int> S2I;
vector<Set> I2S;

int get_id(Set s)
{
    if(S2I.count(s)) return S2I[s];

    I2S.push_back(s);
    S2I[s] = I2S.size() - 1;
    return S2I[s];
}

int main(void)
{
    int T;
    cin >> T;

    while(T--)
    {
        S2I.clear();
        I2S.clear();
        stack<int> sk;
        int n;
        cin >> n;

        while(n--)
        {

            string s;
            cin >> s;
            char op = s[0];
            if(op == 'P')
            {
                sk.push(get_id(Set()));
            }
            else if(op == 'D')
            {
                sk.push(sk.top());
            }
            else
            {
                Set s1 = I2S[sk.top()];
                sk.pop();
                Set s2 = I2S[sk.top()];
                sk.pop();
                Set s_dst;

                if(op == 'U')
                {
                    set_union(s1.begin(), s1.end(), s2.begin(), s2.end(), inserter(s_dst, s_dst.begin()));
                }
                else if(op == 'I')
                {
                    set_intersection(s1.begin(), s1.end(), s2.begin(), s2.end(), inserter(s_dst, s_dst.begin()));
                }
                else if(op == 'A')
                {
                    s_dst = s2;
                    s_dst.insert(get_id(s1));
                }

                sk.push(get_id(s_dst));

            }

            cout << I2S[sk.top()].size() << endl;
        }

        cout << "***" << endl;
    }
}
