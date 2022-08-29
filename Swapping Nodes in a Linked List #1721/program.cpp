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
        curr->next=NULL;
    };

    void printList(){
        ListNode *itr=new ListNode();
        itr=this->head;
        while(itr)
        {
            cout<<itr->val<<" -> ";
            itr=itr->next;
        }
        
    };

    ListNode* getHead(){
        return this->head;
    }
    

    ListNode* swapNodes(ListNode* head, int k) {
        int size = 0, temp, count = 0;
        ListNode* cur;
        for (cur = head; cur != nullptr; cur = cur->next)
        {
            ++size;
            if (size == k)
                temp = cur->val;
        }
        for (cur = head; cur != nullptr; cur = cur->next)
        {
            ++count;
            if (count == size - k + 1)
            {
                swap(cur->val, temp);
                break;
            }
        }
        count = 0;
        for (cur = head; cur != nullptr; cur = cur->next)
        {
            ++count;
            if (count == k)
            {
                cur->val = temp;
                break;
            }
        }
        return head;
    };
};

int main(){
    vector<int> input={100,90};
    Solution obj1;
    obj1.CreateList(input);
    obj1.printList();
    cout<<endl;
    obj1.swapNodes(obj1.getHead(),2);
    obj1.printList();

}