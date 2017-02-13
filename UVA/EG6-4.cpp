#include<iostream>
#include<vector>
#include<string>

using namespace std;

struct node
{
    char ch;
    int next;
};


int main(void)
{
    string s;
    while(getline(cin, s))
    {
        int len = s.size();
        node chains[len + 10];

        for(int i = 1; i <= len; i++)
        {
            chains[i].ch = s[i - 1];
            chains[i].next = -1;
        }

        int head = 0;
        chains[head].ch = 'H';
        chains[head].next = -3;
        int tail = 0;
        int now = 0;
        for(int i = 1; i <= len; i++)
        {
            if(chains[i].ch == '[')
            {
                now = head;
            }
            else if(chains[i].ch == ']')
            {
                now = tail;
            }
            else
            {
                chains[i].next = chains[now].next;
                chains[now].next = i;
                now = i;

                if(chains[i].next == -3) tail = i;

            }

        }
        int index = chains[0].next;
        while(index != -3)
        {
            cout<< chains[index].ch;
            index = chains[index].next;
        }
        cout << endl;

    }
}
