#include <iostream>
#include <vector>
using namespace std;

// following code can be directly copy pasted for leetcode solution

class MyLinkedList {
  struct Node {
    int value;
    Node* next = nullptr;

    Node(int value) : value(value) {
    }
    
    Node(int value, Node* next) : value(value), next(next) {
    }
  };
  

public:
  // head_ is always a sentinel node to maintain invariant that every node in LinkedList has a predecessor.
  MyLinkedList() : head_(new Node(0)), tail_(head_) {
  }
    
  int get(int index) {
    Node* node = findAtIndex(index);
    return node ? node->value : -1;
  }
    
  void addAtHead(int val) {
    if (size_ == 0) {
      // List is empty => to update tail correctly use addTail.
      addAtTail(val); 
      return;
    }
    Node* newbie = new Node(val, head_->next);
    head_->next = newbie;
    ++size_;
  }
    
  void addAtTail(int val) {
    Node* newbie = new Node(val);
    tail_->next = newbie;
    tail_ = newbie;
    ++size_;
  }
    
  void addAtIndex(int index, int val) {
    if (index < 0 || index > size_) return;
    
    if (index == size_) {
      addAtTail(val);
      return;
    }
    
    Node* node = findAtIndex(index - 1);

    Node* newbie = new Node(val, node->next);
    node->next = newbie;
    
    ++size_;
  }
    
  void deleteAtIndex(int index) {
    if (index < 0 || index >= size_) return;
      
    Node* node = findAtIndex(index - 1);

    Node* to_remove = node->next;
    node->next = to_remove->next;
    
    // If we are removing last element update tail_
    if (!to_remove->next) tail_ = node; 
    
    delete to_remove;
    --size_;
  }
  
private:
  
  // Assume index >= -1 && index < size_
  Node* findAtIndex(int index) {
    if (index == -1) return head_;
    
    Node* head = head_->next;
    for (; index != 0 && head; --index) {
      head = head->next;
    }
    return head;
  }
  
private:
  Node* head_;
  Node* tail_;
  size_t size_ = 0;
};

int main(){
}