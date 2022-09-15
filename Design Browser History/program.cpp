#include <iostream>
#include <map>
#include <vector>
using namespace std;

// paste code from here for leetcode solution

class NNode{
    public:
    string url;
    NNode* prev;
    NNode* next;
    NNode(string url):url(url),prev(NULL),next(NULL){}
};

class BrowserHistory {
    int index=0;
    int size=0;
    NNode* current=NULL;
    map<int,NNode*> list;
public:
    
    NNode* addNode(string url){
        NNode* temp=new NNode(url);
        if(this->current==NULL){
            current=temp;
            return temp;
        }
        this->current->next=temp;
        temp->prev=this->current;
        current=temp;
        return this->current;
    }
    
    BrowserHistory(string homepage) {
        this->index++;
        this->size++;
        pair<int,NNode*> newpair(index,addNode(homepage));
        this->list.insert(newpair);
    }
    
    void visit(string url) {
        this->index++;
        this->size=this->index;
       
        map<int,NNode*> ::iterator itr=this->list.find(this->index);
        if(itr!=this->list.end()){
            itr->second=addNode(url);
        }
        else{
            pair<int,NNode*> newpair(index,addNode(url));
            this->list.insert(newpair);
        }
    }
    
    string back(int steps) {
        if(steps>=this->index){
            this->index=1;
            this->current=list[index];
            return this->list[index]->url;
        }
        else{
            this->index=this->index-steps;
            this->current=list[index];
            return this->list[index]->url;
        }
    }
    
    string forward(int steps) {
        if(steps>this->size-this->index){
            this->index=this->size;
            this->current=list[index];
            return this->list[index]->url;
        }
        else{
            this->index=this->index+steps;
            this->current=list[index];
            return this->list[index]->url;
        }
    }
};
int main(){
    BrowserHistory *first=new BrowserHistory("momn.com");
    first->visit("bx.com");
    first->visit("bjyfmln.com");
    cout<<first->back(3)<<endl;
    first->visit("ijtrqk.com");
    first->visit("dft.com");
    cout<<first->back(10)<<endl;
    cout<<first->forward(10)<<endl;
    first->visit("yc.com");
    first->visit("yhl.com");
    first->visit("xynxvix.com");
    first->visit("izfscdv.com");
    first->visit("cdenhm.com");
    first->visit("ocgcjz.com");
    cout<<first->forward(5)<<endl;
    cout<<first->forward(5)<<endl;
    first->visit("gtd.com");
    cout<<first->back(9)<<endl;
    first->visit("hfeour.com");
    first->visit("ghmh.com");
    first->visit("nnm.com");
    first->visit("knm.com");
    cout<<first->forward(4)<<endl;
    first->visit("cbtg.com");
    first->visit("acyvwod.com");
    first->visit("mydr.com");
}