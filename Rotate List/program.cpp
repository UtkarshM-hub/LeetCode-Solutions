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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* temp1 = head;
        int len = 0;
        if(head==NULL || head->next==NULL) return head;
            
        while(temp1->next != NULL){
            len++;
            temp1 = temp1->next;
        }
        temp1 -> next = head;
        
        int r = (len) - k%(len+1);
        ListNode* temp2 = head;
        for(int i=0; i<r; i++){
            temp2 = temp2->next;
        }
        ListNode* ans = temp2->next;
        temp2 -> next = NULL;
        
        return ans;
    }
};
int main(){
    
}