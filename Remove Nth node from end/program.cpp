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
    ListNode *position=NULL;
    int n;
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

void RemoveNth(ListNode*itr){
        if(itr->next==NULL){
            return;
        }
        itr=itr->next;
        RemoveNth(itr);
        this->n-=1;
        if(this->n==1){
            cout<<itr->val<<endl;
            this->position=itr;
        }
        if(this->n==-1){
            itr->next=this->position;
            this->position=NULL;
        }
        return;

    }
    void removeNthFromEnd(ListNode* head, int num){
        vector<int> arr;
        int value;
        int copied;
        ListNode *itr=head;
        while (itr)
        {
            arr.push_back(itr->val);
            itr=itr->next;
        }
        value=arr[arr.size()-1];
        for(int i=arr.size()-2;i>=0;i--){
            if(n==0){
                break;
            }
            copied=arr[i];
            arr[i]=value;
            value=copied;
            n--;

        };
        for(int j=0;j<arr.size();j++){
            cout<<arr[j]<<" ";
        };
    };
};


int main(){
    Solution obj1;
    vector<int> input={1,2,3,4,5};
    obj1.CreateList(input);
    obj1.printList();
    // obj1.removeNthFromEnd(obj1.getHead(),1);
    // obj1.printList();
}