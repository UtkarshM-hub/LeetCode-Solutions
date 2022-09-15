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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head) return head;
        ListNode* ret = new ListNode();
        ret->next = head;
        ListNode* curr = head, *pre = ret;
        while(curr and curr->next){
            if(curr->val == curr->next->val){
                while(curr->next and curr->val == curr->next->val){
                    curr = curr->next;
                }
                pre->next = curr->next;
            }else{
                pre = curr;
            }
            curr = curr->next;
        }
        return ret->next;
    }
};

int main(){
    
}