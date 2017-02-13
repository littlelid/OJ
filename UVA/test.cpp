#include<cstdio>
#include<iostream>
#include<stdlib.h>
#include<sstream>
using namespace std;
/*
struct node
{
    int v;
    node* next;
};

node* head = NULL;

int main(void)
{
    head = new node;
    head->next = NULL;

    int v;
    while(1)
    {
        cin >> v;
        if(v == -1) break;

        node* n = new node;
        n->v = v;
        n->next = head->next;
        head->next = n;
    }

    node* it = head->next;
    while(it)
    {
        cout << it->v << " "; 
        it = it->next;
        
    }
    cout << endl;

    cout << "insert pos and v:" << endl;
    
    int p;
    cin >> p >> v;
    it = head->next;
    while(it != NULL && it->v != p) 
    {
        //cout << "\t!!!: " << it->v << endl;
        it = it->next;
        
    }
    cout << "***" << endl;
    if(it == NULL) {cout << "NOT FOUND" << endl; return 0;}

    node* new_node = new node;
    new_node->v = v;
    new_node->next = it->next;
    it->next = new_node;

    it = head->next;
    while(it)
    {
        cout << it->v << " "; 
        it = it->next;
    }
}
*/
/*
int a[] = {9, 18, 73, 66, 53, 4, 32, 2, 1, 0};

void quicksort(int left, int right)
{
    if(left > right) return;
    cout << left << "," << right << endl;;
    int i = left, j = right;
    int temp = a[left];
    int t;
    while(i < j)
    {
        
        while(a[j] >= temp && i < j) j--;
        while(a[i] <= temp && i < j) i++;
        cout << "\t" << i << "," << j << endl;
        if(i < j)
        {
            cout << "here" << endl;
            t = a[i];
            a[i] = a[j];
            a[j] = t;
        }
    }

    t = a[i];
    a[i] = a[left];
    a[left] = t;

    quicksort(left, i - 1);
    quicksort(i + 1, right);
}

int main(void)
{
    quicksort(0, 9);
    for(int i = 0; i < 10; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    
}
*/