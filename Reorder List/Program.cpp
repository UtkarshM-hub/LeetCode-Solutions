// Link to the Proper LeetCode Solution:
//https://leetcode.com/problems/reorder-list/discuss/2467039/c-solution

#include <iostream>
#include <vector>
using namespace std;

class ListNode{    
    public:
    int val;
    ListNode *next;    
};

class Solution{

    private:
    ListNode *head=NULL;
    ListNode *itr=NULL;
    ListNode *prev=NULL;
    bool stop=false;
    bool first=false;
    public:
    
    void CreateList(vector<int>arr){
        ListNode *curr=new ListNode;
        for(int i=0;i<arr.size();i++){
            ListNode *temp=new ListNode;
            temp->val=arr[i];
            if(head==NULL){
                head=temp;
            }
            curr->next=temp;
            curr=temp;
        };
    };

    void printList(){
        ListNode *itr=new ListNode();
        itr=head;
        while (itr)
        {
            cout<<itr->val<<" -> ";
            itr=itr->next;
        }
        
    };

    ListNode* getHead(){
        return this->head;
    }

    void Reorder(ListNode *Second){
        if(Second->next==NULL){
            return;
        }
        Second=Second->next;
        Reorder(Second);
        if(prev==Second || Second->next==prev){
            this->prev->next=NULL;
            this->stop=true;
        }

        if(!stop){
            if(this->first){
                itr->next=prev;
                itr=prev;
                prev=prev->next;
                itr->next=Second;
                itr=Second;
            }
            else{
                itr->next=Second;
                itr=Second;
                this->first=true;
            }
        }
        return;
    }

    void reorderList(ListNode* head) {
        this->itr=head;
        this->prev=head->next;
        Reorder(head);
        this->itr->next=this->prev;
        prev!=NULL?prev->next=NULL:NULL;
    }
};

int main(){
    vector<int> input={1,2,3,4,5};
    Solution obj1;
    obj1.CreateList(input);
    cout<<"Before: "<<endl;
    obj1.printList();
    cout<<endl;
    obj1.reorderList(obj1.getHead());
    cout<<"After: "<<endl;
    obj1.printList();
}