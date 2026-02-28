#include<iostream>
using namespace std;
class ArrayStack {
    private:
    vector<int>stack;
public:
    ArrayStack() {
    }
    
    void push(int x) {
        stack.push_back(x);
        
   
    }
    
    int pop() {
        int x=stack.back();
        stack.pop_back();
        return x;
  
    }
    
    int top() {
        int y=stack[stack.size()-1];
        return y;
    
    }
    
    bool isEmpty() {
        if(stack.size()==0)
        {
            return true;
        }
        return false;
  
    }
};