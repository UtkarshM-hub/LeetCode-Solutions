#include <iostream>
#include <vector>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* newHead=NULL;
        if(head==NULL || head->next==NULL){
            return head;
        }
        
        ListNode* p=new ListNode();
        p->next=head;
        ListNode* m=head;
        ListNode* a=new ListNode();
        a=m->next;
        while(a!=NULL){   
            ListNode* aNext=a->next;
            a->next=m;
            m->next=aNext;
            p->next=a;
            if(newHead==NULL){
                newHead=p->next;
            }
            p=m;
            m=m->next;
            a=m==NULL?NULL:m->next;
        }
        return newHead;
    }
};
int main(){
    
}