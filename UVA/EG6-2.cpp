#include<cstdio>
#include<iostream>
#include<queue>
#include<stack>
#include<vector>
using namespace std;

int main(void)
{
    int n;
    while(1)
    {

        cin >> n;
        if(n == 0) break;


        int t;
        int flag = 0;
        while(1)
        {
            queue<int> q;
            stack<int> s;
            vector<int> c;
            for(int i = 0; i < n; i++)
            {
                cin >> t;
                if(t == 0)
                {
                    flag = 1;
                    break;
                }
                c.push_back(t);
            }
            if(flag) break;

            for(int i = 1; i <= n; i++)
            {
                q.push(i);
            }

            int len = c.size();

            int max_ = 0;
            int flag1 = 0;
            int flag2 = 0;

            for(int i = 0; i < len; i++)
            {

                int p = c[i];
                if(p > max_)
                {
                    flag1 = 0;
                    while(!q.empty())
                    {
                        int temp = q.front();

                        q.pop();
                        s.push(temp);

                        if(temp == p)
                        {
                            flag1 = 1;
                            break;
                        }
                    }
                    if(flag1 == 0)
                    {
                        flag2 = 1;
                        break;
                    }
                    max_ = p;
                }

                if(!s.empty() && s.top() != p)
                {
                    flag2 = 1;
                    break;
                }
                else
                {
                    s.pop();
                }


                if(flag2) break;

            }
            if(flag2)
            {
                cout << "No" << endl;
            }
            else
            {
                cout << "Yes" << endl;
            }

        }

        cout << endl;




    }

}
