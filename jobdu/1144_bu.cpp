#include<cstdio>
#include<iostream>
#include<math.h>
#include<vector>
#include<algorithm>
using namespace std;

struct edge
{
    int u;
    int v;
    double length;
    edge(int u, int v, double length):u(u),v(v),length(length){}

    bool operator < (const edge &o) const
    {
        return length < o.length;
    }
};

double x[105];
double y[105];
int father[105];

int find(int i);
vector<edge> edges;

int main(void)
{
    int n;
    while(cin >> n)
    {
        for(int i = 0; i < n; i++) father[i] = i;
        for(int i = 0; i < n; i++) cin >> x[i] >> y[i];
        for(int i = 0; i < n; i++)
        {
            for(int j = i + 1; j < n; j++)
            {
                double length = (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);
                edges.push_back(edge(i, j, sqrt(length)));
            }
        }

        sort(edges.begin(), edges.end());
        
        //for(int i = 0; i < edges.size(); i++) cout << edges[i].length << endl;
        //int cnt = 0;
        double ans = 0;
        for(int i = 0; i < edges.size(); i++)
        {
            int u = edges[i].u;
            int v = edges[i].v;
            int f1 = find(u);
            int f2 = find(v);
            if(f1 != f2) 
            {
                //cout << '\t' << x[u] << ' ' << y[u] << ',' << x[v] << ' ' << y[v] << ' ' << edges[i].length << endl;
                father[f1] = f2;
                ans += edges[i].length;
                //:cnt += 1;
                //for(int i = 0; i < n; i++) cout << find(i) << ' ';
                //cout << endl;
                //cout << "father:" << find(u) << ", " << find(v) << endl;
            }
            //if(cnt == n - 1) break;
        }
        printf("%.2lf\n", ans);

    }
}
int find(int i)
{
    return father[i] == i ? i : father[i] = find(father[i]);
}

