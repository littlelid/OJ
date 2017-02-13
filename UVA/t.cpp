#include<cstdio>
#include<iostream>
using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};
ListNode* FindKthToTail(ListNode* pListHead, unsigned int k);
int main(void)
{
    ListNode* t1 = new ListNode(3);
    ListNode* t2 = new ListNode(2);
    ListNode* t3 = new ListNode(1);
    ListNode* t4 = new ListNode(5);
    t1->next = t2;
    t2->next = t3;
    t3->next = t4;
    ListNode* temp = FindKthToTail(t1, 4);
    if(temp == NULL) cout << "&&&";
    else cout << "***" << temp->val << endl;
}

ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
    	if(pListHead == NULL || k <= 0) return NULL;
        ListNode *p1;
        p1 = pListHead;
       	
        int num = 0;
        while(p1 != NULL)
        {
            num++;
            p1 = p1->next;
        }
        //cout << num << endl;
        int count = num - k;
        if(count < 0) return NULL;
        //cout << count << endl;
        p1 = pListHead;
        
        while(count > 0)
        {
            count--;
            //cout << "\t" << p1->val << count << endl;
            p1 = p1->next;
        }
        return p1;
       
};