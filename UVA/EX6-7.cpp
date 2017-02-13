#include<cstdio>
#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;

struct node
{
    int flag;
    int value;
    node* left;
    node* right;
    node():flag(0),left(NULL),right(NULL){}
};

node* newnode();
int addnode(int v, char* s);
int read();
void bfs();
void print();


node* root;
vector<int> ans;
int failed;
char s[1000];

int main(void)
{
    while(read())
    {
        //printf("\tread complete\n");
        if(failed) cout << "not complete" << endl;
        else
        {
            bfs();
            print();
        }

    }

}

node* newnode()
{
    return new node();
}

int addnode(int v, char* s)
{
    //printf(" %s\n", s);
    int len = strlen(s) - 1;
    node* u = root;
    for(int i = 0; i < len; i++)
    {
        char ch = s[i];
        if(ch == 'L')
        {
            if(u->left == NULL) u->left = newnode();
            u = u->left;
        }
        else
        {
            if(u->right == NULL) u->right = newnode();
            u = u->right;
        }
    }
    if(u->flag == 1) failed = 1;
    u->flag = 1;
    u->value = v;
}

int read()
{
    failed = 0;
    root = newnode();
    while(1)
    {
        if(scanf("%s", s) != 1) return 0;
        if(!strcmp(s, "()")) break;
        int v;
        //printf("\tHERE2\n");
        sscanf(&s[1], "%d", &v);
        //printf("%d", v);
        addnode(v, strchr(s, ',') + 1);
        //printf("\tHERE3\n");
    }

    return 1;
}

void bfs()
{
    ans.clear();
    queue<node*> q;
    node* u = root;
    q.push(u);
    while(q.size())
    {
        node* t = q.front();
        q.pop();
        if(t->flag == 0)
        {
            failed = 1;
            break;
        }
        ans.push_back(t->value);

        if(t->left) q.push(t->left);
        if(t->right) q.push(t->right);



    }
}

void print()
{
    if(failed)
    {
        cout << "not complete" << endl;
    }
    else
    {
        int len = ans.size();
        for(int i = 0; i < len; i++)
        {
            if(i == 0) cout << ans[i];
            else       cout << " " << ans[i];
        }
        cout << endl;
    }

}

