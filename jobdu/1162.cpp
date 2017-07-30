#include<iostream>
#include<cstdio>
#include<string.h>
using namespace std;

int N, M;
int MAX = 10000000;
int find_min(int dist[], int select[]);
void dijkstra(int graph[][605], int dist[], int src);
int main(void)
{
    while(1)
    {
        int graph[605][605];
        int team[605];
        cin >> N;
        if(N == 0) break;

        memset(graph, -1, sizeof(graph));

        cin >> M;
        int  a, b, t;
        for(int i = 0; i < M; i++)
        {
            cin >> a >> b >> t;
            graph[a][b] = t;
            graph[b][a] = t;
        }

        for(int i = 1; i <= N; i++) 
            cin >> team[i];
        
        int new_graph[605][605];
        //cout << N << endl;
        for(int i = 1; i <= N; i++)
        {
            for(int j = 1; j <= N; j++)
            {
                if(team[i] != team[j])
                {
                    new_graph[i][j] = -1;
                    //cout <<  endl  << "****" << team[i] << ' ' << team[j]  <<  graph[i][j];
                }
                else
                    new_graph[i][j] = graph[i][j];
                
                //cout << new_graph[i][j] << ' ';
            }
            //cout << endl;
        
        }
        int dist1[605];
        int dist2[605];

       dijkstra(new_graph, dist1, 1);
       //cout << "***" << endl;
       dijkstra(new_graph, dist2, 2);
       //cout << "***" << endl;

       //for(int i = 1; i <= N; i++) cout << dist1[i] << ' ';
       //cout << endl;
       //for(int i = 1; i <= N; i++) cout << dist2[i] << ' ';
       //cout << endl;
       
       int min_dist = MAX;
       
       for(int i = 1; i <= N; i++)
       {
           for(int j = i + 1; j <= N; j++)
           {
               if(graph[i][j] != -1 and team[i] != team[j]) 
                {
                    if(team[i] == 1) 
                    {
                        if (dist1[i] + graph[i][j] + dist2[j] < min_dist)
                            min_dist = dist1[i] + graph[i][j] + dist2[j];
                    }
                    else
                    {
                        if (dist2[i] + graph[i][j] + dist1[j] < min_dist)
                            min_dist = dist2[i] + graph[i][j] + dist1[j];
                        
                    }
                }

           }

       }
        
        //cout << "ans: ";
       if(min_dist >= MAX) cout << "-1" << endl;
       else  cout << min_dist << endl;
    }

}

int find_min(int dist[], int select[])
{
    int min_dist = MAX;
    int min_idx = 0;
    for(int i = 1; i <= N; i++)
    {
        if(select[i] == 0 && dist[i] < min_dist)   
        {
            min_idx = i;
            min_dist = dist[i] ;
        }
    }
    return min_idx;

}
void dijkstra(int graph[][605], int dist[], int src)
{
    int select[605];
    for(int i = 1; i <= N; i++)    
    {
        select[i] = 0;
        dist[i] = MAX;
    }

    dist[src] = 0;
    
    for(int i = 1; i <= N; i++ )
    {
        int u = find_min(dist, select);
        if (u == 0) break;

        select[u] = 1;
        
        //cout << "u = " << u << endl;
        for(int v = 1; v <= N; v++)
        {
            //cout << "\tv = " << v << endl;
            if(select[v] == 0 && graph[u][v] != -1 && dist[u] + graph[u][v] < dist[v])
            {
                //cout << '\t' << dist[u]  << ' ' <<  graph[u][v] << endl;
                //cout << '\t' << dist[u] + graph[u][v] <<  " " << dist[v] <<endl;
                dist[v] = dist[u] + graph[u][v];
            }
        }
       //for(int i = 1; i <= N; i++) cout << dist[i] << ' ';
       //cout << endl;
    
    }
}


