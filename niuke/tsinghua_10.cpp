#include<cstdio>
#include<iostream>
#include <algorithm>
#include<vector>
#include<string.h>
#include<stack>
using namespace std;


struct node
{
    char v;
    node* left;
    node* right;
    node(int v, node* left, node* right):v(v), left(left), right(right){}
};

node* build();
void print(node* n);
string s;
int cur = 0;
int len;
int main(void)
{
    
    while(cin >> s)
    {   
        cur = 0;
        len = s.size();
        node* tree = build();
        print(tree);
        cout << endl;
        //cout << "***" << endl;
    }

}

node* build()
{
    
    if(s[cur] == '#') return NULL;

    node* n = new node(s[cur], NULL, NULL);
    if(cur + 1 < len)
    {
        ++cur;
        n->left = build();
    }
    if(cur + 1 < len)
    {
        ++cur;
        n->right = build();
    } 
    return n;
}

void print(node* n)
{
    if(n == NULL) return;
    print(n->left);
    cout << n->v << " ";
    print(n->right);
}
