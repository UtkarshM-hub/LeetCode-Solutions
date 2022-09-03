#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class ListNode{
    public:
    int val;
    ListNode *next;
    ListNode(): val(0),next(nullptr) {}
    ListNode(int x) : val(x),next(nullptr) {}
};

class Solution {

    ListNode *head1=NULL;
    ListNode *head2=NULL;
public:
    void createList(vector<int> list,int num){
        ListNode *current=NULL;
        for(int i=0;i<list.size();i++){
            ListNode *temp=new ListNode();
            temp->val=list[i];
            temp->next=NULL;
            if(head1==NULL && current==NULL && num==1){
                current=head1=temp;
                continue;
            } 
            if(head2==NULL && current==NULL && num==2){
                current=head2=temp;
                continue;
            }
            current->next=temp;
            current=temp;
        };
    }

    void printList(int num){
        ListNode *itr=new ListNode();
        itr=num==1?head1:head2;
        while (itr)
        {
            cout<<itr->val<<" -> ";
            itr=itr->next;
        }
        
    };

    ListNode* getHead(int num){
        return num==1?this->head1:this->head2;
    }

    // code from here can be copied for leetcode solution
    void list2stack(stack<int> &st, ListNode* head){
        while(head){
            st.push(head->val);
            head = head->next;
        }
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        stack<int> st1;
        list2stack(st1, l1);
        stack<int> st2;
        list2stack(st2, l2);
        
        ListNode* head = NULL;
        int carry = 0;
        
        while(!st1.empty() || !st2.empty() || carry){
            
            int s = 0;
            if(!st1.empty()){
                s += st1.top();
                st1.pop();
            }
            if(!st2.empty()){
                s += st2.top();
                st2.pop();
            }
            
            s += carry;
            carry = s/10;
            ListNode* ans = new ListNode(s%10);
            ans->next = head;
            head = ans;
            
        }
        
        return head;
        
    }
};

int main(){
    Solution obj1;
    vector<int> input1={1,2,3,4,6};
    vector<int> input2={8,2,3,4};
    obj1.createList(input1,1);
    obj1.createList(input2,2);
    ListNode *newHead=obj1.addTwoNumbers(obj1.getHead(1),obj1.getHead(2));
    while (newHead)
    {
        cout<<newHead->val<<" -> ";
        newHead=newHead->next;
    }
    
}