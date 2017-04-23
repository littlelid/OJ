#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<algorithm>
#include<stdlib.h>
#include<string.h>
using namespace std;

int best = 50;


typedef vector<char> v_char;
map<char, v_char>::iterator it;

v_char ans;

void dfs(v_char perm, v_char node , map<char, v_char> node_2_neb);
int distance(v_char perm, map<char, v_char> node_2_neb);
int rel[26][26];
int visit[26];
int main(void)
{
    while(1)
    {
        string line;
        cin >> line;
        if(line == "#") break;

        memset(rel, 0, sizeof(rel));
        memset(visit, 0, sizeof(visit));
        typedef vector<char> v_char;
        map<char, v_char> node_2_neb;
        v_char node;

        int cur = 0;
        int start = 0;
        while(1)
        {
            start = cur;
            while(cur < line.size() && line[cur]!=';') cur++;

            for(int i = start + 2; i < cur; i++)
            {
                rel[line[start]- 'A'][line[i] - 'A'] = 1;
                rel[line[i]- 'A'][line[start] - 'A'] = 1;       
            }
            cur++;
            if (cur >= line.size()) break;
        } 
        for(int i = 0; i < 26; i++)
        {
            v_char tmp;
            for(int j = 0; j < 26; j++)
            {
                if(rel[i][j] == 1) tmp.push_back('A' + j);
            }
            if(tmp.size()) {
                node.push_back('A' + i);
                node_2_neb['A' + i] = tmp;
            } 
        }
       /* 
        for(int i = 0; i < node.size(); i++)
        {
            cout << node[i] << endl;
            v_char neb = node_2_neb[node[i]];
            cout << '\t';
            for(int j = 0; j < neb.size(); j++)
            {
                cout << neb[j] << ' ';
            }
            cout << endl;

        }
        */
        v_char perm;       
        best = 50;
        dfs(perm, node, node_2_neb);

        for(int i = 0; i < ans.size(); i++)
        {
            if(i) cout << " " << ans[i];
            else cout << ans[i];
        }
        cout << " -> " << best << endl;

    }

}
void dfs(v_char perm, v_char node , map<char, v_char> node_2_neb)
{
    int cur = perm.size();
    int n = node.size();
    if(cur >= n)
    {
        //for(int i = 0; i < cur; i++)
        //    cout << perm[i];
        //cout << endl;
        int dis = distance(perm, node_2_neb);
        if(dis < best)
        {
            best = dis;
            ans.assign(perm.begin(), perm.end());
        }
        return;
    }
    
    for(int i = 0; i < node.size(); i++)
    {
        if(visit[node[i] - 'A'] == 1)
            continue;
        v_char neb = node_2_neb[node[i]];
        int cnt = 0;
        for(int j = 0; j < neb.size(); j ++)
        {
            if (visit[neb[j] - 'A'] == 0) cnt += 1;
        }
        if(cnt > best) continue;
        perm.push_back(node[i]);
        visit[node[i] - 'A'] = 1;
         
        dfs(perm, node, node_2_neb);
        perm.pop_back();
        visit[node[i] - 'A'] = 0;
    }

}
int distance(v_char perm, map<char, v_char> node_2_neb)
{
    int max = -1;
    for(int i = 0; i < perm.size(); i++)
    {
        int temp_max = -1; 
        v_char neb = node_2_neb[perm[i]];
        for(int j = 0; j < neb.size(); j++)
        {
            int k = 0;

            while(perm[k] != neb[j]) k++;

            int dis = k - i;
            if(dis < 0) dis = -dis;
            if (dis > temp_max) temp_max = dis;
        }
        if (temp_max > max) max = temp_max;

    }
    return max;

}
