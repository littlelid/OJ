#include<cstdio>
#include<iostream>
#include<vector>

using namespace std;

int main(void)
{
    int T;
    cin >> T;
    while(T--)
    {
        int n, pos;
        cin >> n >> pos;

        vector<int> myQueue;
        vector<int> myFlag;
        for(int i = 0; i < n; i++)
        {
            int temp;
            cin >> temp;
            myQueue.push_back(temp);
            myFlag.push_back(1);
        }

        int prio = myQueue[pos];

        int num = 0;
        int index = 0;
        for(int p = 9; p > prio; p--)
        {
            int this_end = (index + n - 1) % n;
            for(int j = index; j != this_end; j = (j + 1) % n)
            {
                if(myQueue[j] == p)
                {
                    index = j;
                    num++;
                }
            }

            if(myQueue[this_end] == p)
            {
                index = this_end;
                num++;
            }

        }

        for(int j = index; j != pos; j = (j + 1) % n)
        {
            if(myQueue[j] == prio) num++;

        }
        num++;

        cout << num << endl;

    }

}
