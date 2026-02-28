#include<iostream>
using namespace std;
#include<stack>
#include<string>
class Solution {
public:
    string postToInfix(string s) {
        stack<string>st;
        for(char ch:s)
        {
            if(isalnum(ch))
            {
                st.push(string(1,ch));
            }
            else{
                string op2=st.top();st.pop();
                string op1=st.top();st.pop();
                string temp='('+op1+string(1,ch)+op2+')';
                st.push(temp);
            }
        }
        return st.top();
        
    }
};
int main()
{
    Solution s;
    string m;
    cout<<"enter expression"<<endl;
    cin>>m;
    s.postToInfix(m);
}
