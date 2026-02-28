#include<iostream>
using namespace std;
class LinkedListStack {
private:
struct Node{
    int data;
    Node *next;
};
Node*head=NULL;
public:
    LinkedListStack() {

    }
    
    void push(int x) {
        Node* m=new Node;
        m->data=x;
        m->next=head;
        head=m;
    }
    
    int pop() {
        Node*m=head;
        int s=head->data;
        if(head!=NULL)
        {
            head=m->next;
            delete m;
    }
    return s;
    }
    
    int top() {
       return head->data;
    }
    
    bool isEmpty() {
        if(head==NULL)
        {
            return true;
        }
    return false;
  
    }
};