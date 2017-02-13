#include<cstdio>
#include<string>
#include<vector>
#include<iostream>

using namespace std;
const int maxn = 30;
int n;
vector<int > piles[maxn];

void clean_above(int p, int h);
void pile_block(int p_org, int h_org, int p_dst);
void find_location(int a, int& p, int& h);
void print();
int main(void)
{
    int a, b;
    cin >> n;
    string s1, s2;

    for(int i = 0; i < n; i++) piles[i].push_back(i);
    while(1)
    {
        cin >> s1;
        if(s1 == "quit")
        {
            break;
        }
        cin >> a >> s2 >> b;
        //cout << "\tread " << s1 << ' ' << a << ' ' << s2 << ' ' << b << '\n';
        int pa, ha, pb, hb;

        find_location(a, pa, ha);
        find_location(b, pb, hb);
        //cout << "\tloc1\n";
        if(pa == pb) continue;
        if(s1 == "move") clean_above(pa, ha);
        //cout << "\tloc2\n";
        if(s2 == "onto") clean_above(pb, hb);
        //cout << "\tloc3\n";
        pile_block(pa, ha, pb);
        //cout << "\tloc4\n";

    }
    print();

}

void clean_above(int p, int h)
{
    for(int i = h + 1; i < piles[p].size(); i++)
    {
        int temp = piles[p][i];
        piles[temp].push_back(temp);
    }
    piles[p].resize(h + 1);

}
void pile_block(int p_org, int h_org, int p_dst)
{
    //printf("\t p_org: %d, h_org: %d, p_dst: %d, size %d\n", p_org, h_org, p_dst, piles[p_org].size());


    for(int i = h_org; i < piles[p_org].size(); i++)
    {
        //printf("\ti:%d, insert: %d\n", i, piles[p_org][i]);
        piles[p_dst].push_back(piles[p_org][i]);
    }
    piles[p_org].resize(h_org);

}
void find_location(int a, int& p, int& h)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < piles[i].size(); j++)
        {
            if(piles[i][j] == a)
            {
                p = i;
                h = j;
                return;
            }
        }
    }
}
void print()
{
    for(int i = 0; i < n; i++)
    {
        printf("%d:", i);
        for(int j = 0; j < piles[i].size(); j++)
        {
            printf(" %d", piles[i][j]);
        }
        printf("\n");
    }

}
