#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<stack>
using namespace std;

int MAX = 99999;
int graph[105][105];
int distance_[105];
void spread(int graph[][105], int  distance_[], int start);
int n;
int main(void)
{
    while(1)
    {
        cin >> n;
        if(n == 0) break;
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                graph[i][j] = MAX;
        //memset(graph, MAX, sizeof(graph));
        for(int i = 1; i <= n; i++)
        {
            int t, j, d;
            cin >> t;
            while(t--)
            {
                cin >> j >> d;
                graph[i][j] = d;
            }
            graph[i][i] = 0;
        }
        //for(int i = 1; i <= n; i++)
        //{
        //  for(int j = 1; j <= n; j++)
        //        cout << graph[i][j] << ' ';
        //    cout << endl;
        //}            
        //cout << endl << endl;
        int ans = MAX;
        int start = -1;
        for(int i = 1; i <= n; i++)
        {
            //memset(distance_, MAX, sizeof(distance_));
            for(int j = 1; j <= n; j++)
                distance_[j] = MAX;

            spread(graph, distance_, i);
            int max_ = -1;
            for(int i = 1; i <= n; i++)
            {
                //cout << distance_[i] << ' ';
                if(distance_[i] > max_) max_ = distance_[i];
            }
            //cout << endl;
            if (ans > max_){ ans = max_; start = i;}
        }
        if(start != -1)
            cout << start << ' ' << ans << endl;
        else
            cout << "disjoint" << endl;

    }
}

void spread(int graph[][105], int  distance_[], int start)
{
    int select[105];
    for(int i = 1; i <= n; i++) select[i] = 0;
    
    stack<int> node;
    stack<int> dis;
    node.push(start);
    dis.push(0);

    while(!node.empty())
    {
        int s = node.top(); node.pop();
        int d = dis.top(); dis.pop();
        if(d < distance_[s])
        {
            distance_[s] = d;
            //cout << n << ':' << d << endl;
        }
        if(select[s]) continue;
            
        select[s] = 1;
          
        for(int j = 1; j <= n; j++)
        {
            if(s != j && graph[s][j] < MAX)
            {
                //cout << j << endl;
                node.push(j);
                
                dis.push(d + graph[s][j]);
                //cout << '\t' << "from:" << s << " push:" << j << ' ' << d  << '+' <<  graph[s][j]  << endl;
            }
            else
            {
                //cout << "\t" << "debug:" << s << " " << j << ' ' << graph[s][j] << endl;
            }
        }
    
    }
}

