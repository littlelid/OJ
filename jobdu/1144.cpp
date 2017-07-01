#include<cstdio>
#include<iostream>
#include<math.h>
#include<algorithm>
#include<vector>
using namespace std;

struct edge
{
    int u;
    int v;
    double length;
    
    //edge(int u, int v, double length):u(u),v(v),length(length){}

    bool operator < (const edge &o) const
    {
        return length < o.length;
    }
};
vector<edge> edges;

double x[105];
double y[105];
int father[105];

int find(int i);
int main(void)
{
    int n;
    while(cin >> n)
    {
        for(int i = 0; i < n; i++) father[i] = i;
        for(int i = 0; i < n; i++) cin >> x[i] >> y[i];
        int size = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = i + 1; j < n; j++)
            {
                double length = (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);
                //edges[size].u = i;
                //edges[size].v = j;
                //edges[size].length = sqrt(length);
                edge e;
                e.u = i;
                e.v = j;
                e.length = sqrt(length);
                edges.push_back(e);
                //edges.push_back(edge(i, j, sqrt(length)));
                size += 1;
            }
        }

        //sort(edges, edges + size);
        sort(edges.begin(), edges.end());
        
        double ans = 0;
        for(int i = 0; i < size; i++)
        {
            int f1 = find(edges[i].u);
            int f2 = find(edges[i].v);
            if(f1 != f2) 
            {
                father[f1] = f2;
                ans += edges[i].length;
            }
        }
        printf("%.2lf\n", ans);

    }
}
int find(int i)
{
    return father[i] == i ? i : father[i] = find(father[i]);
}

