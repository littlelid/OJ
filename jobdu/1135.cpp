#include<cstdio>
#include<iostream>
#include<string>
#include<sstream>
#include<algorithm>
#include<vector>

using namespace std;

struct node{
    string n;
    node(string n):n(n) {}

    bool operator < (const node& other) const
    {
        return n.size() < other.n.size();
    }
};

int main(void)
{
    int n;
    while(cin >> n)
    {
        getchar();
        vector<node> lines;
        string line;
        while(n--)
        {
            getline(cin, line);
            if (line == "stop") break;
            //cout << "t: " << line << endl;
            lines.push_back(node(line));
        }
        
        sort(lines.begin(), lines.end());
        for(int i = 0; i < lines.size(); i++)
        {
            cout << lines[i].n << endl;
        }

    
    }


}
