#include<cstdio>
#include<iostream>
#include<string.h>
#include<vector>
#include<algorithm>
using namespace std;


vector<int> ans;

int to10(int n);
int to5(int n);
int map[70][70];
int sum_map[70][70];
void dfs(int ul_x, int ul_y, int dr_x, int dr_y, int path);

int n;
int num_node;

void paint(int path);
void draw(int ul_x, int ul_y, int dr_x, int dr_y);


int main(void)
{
   int img = 0; 
   int first = 1;
   while(1)
   {
        
        cin >> n;
        getchar();
        if(n == 0) break;

        if(first) first = 0;
        else      cout << endl;
        num_node = 0;
        memset(map, 0, sizeof(map));
        
        if(n > 0)
        {
            ans.clear();
            memset(sum_map, 0, sizeof(sum_map));
            char ch;
            for(int i = 1; i <=n; i++)
            {
                
                for(int j = 1; j <=n; j++)
                {
                
                    map[i][j] = getchar() - '0';
                    
                }
                getchar();
            }
            
          
            for(int i = 1; i <=n; i++)
            {
                for(int j = 1; j <=n; j++)
                {
                    sum_map[i][j] = sum_map[i-1][j] + sum_map[i][j-1] + map[i][j] - sum_map[i-1][j-1];
                }
            }
            
            
            //cout << "***" << endl;
            
            dfs(0, 0, n, n, 0);
            sort(ans.begin(), ans.end());
            /*
            ans.clear();
            for(int i = 1; i <=24; i++)
                ans.push_back(i);
            */
            img++;
            cout << "Image " << img << endl; 
            for(int i = 0; i < ans.size(); i++)
            {
                cout << ans[i];
                if((i+1) % 12 != 0 ) 
                {
                     if(i+1 != ans.size())  cout << " " ;
                }
                else                cout << endl;
            }
            if(ans.size() % 12 != 0) cout << endl;
            cout << "Total number of black nodes = " << ans.size() << endl;
                        
            //cout << endl;
        }
        else
        {
            n = -n;
            int t;
            while(1)
            {
                cin >> t;
                if(t == -1) break;

                paint(t);
            }
            img++;
            cout << "Image " << img << endl; 
            for(int i = 1; i <=n; i++)
            {
                for(int j = 1; j <=n; j++)
                {
                    if(map[i][j]) cout << "*";
                    else          cout << ".";
                }
                cout << endl;
            }
            //cout << endl;
        }
   }
}
int to10(int n)
{
    int num = 0;
    while(n)
    {
        num *= 5;
        num += n % 10;
        n = n / 10;
        
    }
    return num;
}

void dfs(int ul_x, int ul_y, int dr_x, int dr_y, int path)
{
    //cout << "(" << ul_x<< "," << ul_y << "," << dr_x<< "," << dr_y<< "," << path << ")" << endl;
    int sum_dark = sum_map[dr_x][dr_y] - sum_map[ul_x][dr_y] - sum_map[dr_x][ul_y] + sum_map[ul_x][ul_y];
    if(sum_dark == 0) return;

    int sum_box = (dr_x - ul_x)*(dr_y - ul_y);
    //cout << "\t" << "sum_dark = " << sum_dark << endl;
    if(sum_dark == sum_box)
    {
        //cout << "\tpush_back" << endl;
        ans.push_back(to10(path));
    }
    else
    {
        int x = ul_x + (dr_x - ul_x)/ 2, y = ul_y + (dr_y - ul_y)/ 2;
        
        dfs(ul_x, ul_y,    x,    y, path*10+1);  //NW
        dfs(ul_x,    y,    x, dr_y, path*10+2);  //NE
        dfs(   x, ul_y, dr_x,    y, path*10+3);  //SW
        dfs(   x,    y, dr_x, dr_y, path*10+4);  //SE
    } 
}



void paint(int path)
{
    int ul_x = 0, ul_y = 0, dr_x = n, dr_y = n;
    int x, y;
    while(path)
    {
        x = ul_x + (dr_x - ul_x)/ 2;
        y = ul_y + (dr_y - ul_y)/ 2;
        int t = path % 5;
        path /= 5;
        if(t == 1)
        {
            dr_x = x;
            dr_y = y;
        }
        else if(t == 2)
        {
            ul_y = y;
            dr_x = x;
        }
        else if(t == 3)
        {
            ul_x = x;
            dr_y = y;
        }
        else if(t == 4)
        {
            ul_x = x;
            ul_y = y;
        }
    }
    //cout << "drawing: (" << ul_x<< "," << ul_y << "," << dr_x<< "," << dr_y<< "," << path << ")" << endl;
    draw(ul_x, ul_y, dr_x, dr_y);
}
void draw(int ul_x, int ul_y, int dr_x, int dr_y)
{
    for(int i = ul_x + 1; i <= dr_x; i++)
    {
        for(int j = ul_y + 1; j <= dr_y; j++)
        {
            map[i][j] = 1;
        }
    }
}
/*
int to5(int n)
{
    int num = 0;
    while(n)
    {
        num *= 10;
        num += n % 5;
        n /= 5;
    }
    return num;
}
*/