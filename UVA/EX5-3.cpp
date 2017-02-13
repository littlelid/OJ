#include<iostream>
#include<queue>

using namespace std;

int main(void)
{
    int n;


    while(1)
    {
        cin >> n;
        if(n == 0) break;

        queue<int> q;
        vector<int>  dis;
        for(int i = 1; i <= n; i++)
        {
            q.push(i);
        }

        while(q.size() > 1)
        {
            int t1 = q.front();
            q.pop();
            dis.push_back(t1);

            int t2 = q.front();
            q.pop();
            q.push(t2);

        }


        cout << "Discarded cards:";

        int flag2 = 1;
        for(int i = 0; i < dis.size(); i++)
        {
            if(flag2)
            {
                flag2 = 0;
                cout << " " << dis[i];
            }
            else
            {
                cout << ", " << dis[i];
            }
        }
        cout << endl;
        cout << "Remaining card: " << q.front() << endl;
    }




}
