#include<iostream>
using namespace std;
class LinkedListQueue {
private:
struct Node{
    int data;
    Node*next;
};
Node*head=NULL;
public:
    LinkedListQueue() {
    }
    
    void push(int x) {
        Node*m=new Node ;
        m->data=x;
        if(head==NULL)
        {
            m->next=head;
            head=m;
        }
        else
        {
            Node*s=head;
            while(s->next!=NULL)
            {
                s=s->next;
            }
            s->next=m;
            m->next=NULL;
        }
   
    }
    
    int pop() {
        int x=head->data;
        Node *m=head;
        head=m->next;
        delete m;
        return x;
    }
    
    int peek() {
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