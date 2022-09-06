//link to the explanation 
// https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/discuss/2538058/EASY-4ms-C%2B%2B-Solution

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};

class Solution {
    Node* resultHead=NULL;
    Node* current=NULL;
public:
    
	//create doubly linked list
    void Add(int val){
        Node* temp=new Node();
        temp->val=val;
        temp->next=NULL;
        temp->prev=NULL;
        if(this->resultHead==NULL){
            this->resultHead=temp;
            this->current=temp;
            return;
        }
        this->current->next=temp;
        temp->prev=this->current;
        this->current=temp;
    }
    
    Node* flatten(Node* head) {
        stack<Node*> parent;
        Node* curr=head;
        
        while(curr!=NULL || !parent.empty()){
            if(curr==NULL){
                curr=parent.top();
                parent.pop();
                curr=curr->next;
                continue;
            }
            Add(curr->val);
            if(curr->child!=NULL){
                parent.push(curr);
                curr=curr->child;
                continue;
            }
            if(curr->next==NULL && !parent.empty()){
                curr=parent.top();
                parent.pop();
            }
            curr=curr->next;
        }
        return this->resultHead;
    };
};
int main(){
    
}
