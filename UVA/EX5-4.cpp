#include<cstdio>
#include<map>
#include<iostream>
using namespace std;


struct node
{
    int x, y;
    node(int x, int y):x(x), y(y){}

    bool operator < (const node& r) const {return x < r.x || (x == r.x && y < r.y);}
};


int main()
{
    int n;
    while(1)
    {
        cin >> n;
        if(n == 0) break;

        map<node, int>data;
        map<node, int>::iterator it;

        while(n--)
        {
            int a, b;
            cin >> a >> b;

            node p(b, a);

            it = data.find(p);

            if(it != data.end())
            {

                if(data[p] == 1)
                {
                    data.erase(it);

                }
                else
                {
                    data[p]--;

                }
            }
            else
            {

                node q(a, b);

                if(data.count(q))
                {
                    data[q] = data[q] + 1;

                }
                else
                {
                    data[q] = 1;

                }
            }
        }
        if(data.size() == 0)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

}

/*
    map<node, int>data;
    map<node, int>::iterator it;

    node p(1, 2);
    data[p] = 1;
    it = data.find(p);
    if(it != data.end()) cout << "find" << endl;
    cout << data.count(p);
    for (it = data.begin(); it != data.end(); ++it)
            {
                cout << "\t(" << it->first.x << ", " << it->first.y << ") =" << it->second << endl;
            }
            //cout << "\t" << it->first << "=" << it->second << endl;
*/
