#include<cstdio>
#include<iostream>
#include<map>
#include<vector>
#include<string>
#include<string.h>

using namespace std;

map<string, int>::iterator it;

int proxy_used[1005];

int main(void)
{
    int n, m;
    while(cin >> n)
    {
        memset(proxy_used, 0, sizeof(proxy_used));

        map<string, int> proxy_map;
        vector<string> proxy, server;

        string ip;
        for(int i = 0; i < n; i++)
        {
            cin >> ip;
            proxy_map[ip] = 0;
            proxy.push_back(ip);
        }
        cin >> m;
        for(int i = 0; i < m; i++)
        {
            cin >> ip;
            server.push_back(ip);
        }
        
        int cnt = 0;
        int ans = 0;
        int flag = 0;
        for(int i = 0; i < server.size(); i++)
        {
            if(proxy_map.count(server[i]) == 1)
            {
                flag = 1;
                if(proxy_map[server[i]] == 0)
                {
                    proxy_map[server[i]] = 1;
                    cnt += 1; 
                    if(cnt >=  proxy.size())
                    {
                        ans += 1;
                        cnt = 0;
                        for(it = proxy_map.begin(); it != proxy_map.end(); it++)
                            it -> second = 0;
                    }
                }
            }
        }
       if (n == 1  && flag) cout << "-1" << endl;
       else cout << ans << endl; 
    }
    

}
