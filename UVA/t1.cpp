#include<cstdio>
#include<iostream>
using namespace std;

struct node
{
    int val;
    struct node* next;
    node(int v):val(v),next(NULL){}
    bool operator < (const node& other) const{
        return val < other.val;
    }
};

node* function (node* head1, node* head2)
{
    return NULL;
}

int main(void)
{
    node* n1 = new node(1);
    node* n2 = new node(2);
    n1->next = n2;

    cout << n1->next->val << endl;
}   
