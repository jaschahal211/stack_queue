#include<iostream>
#include<string>
#include<stack>
using namespace std;
 class Solution {
public:
    string postfixToPrefix(const string& s) {
        stack<string>st;
       for(char ch:s)
       {
        if(isalnum(ch))
        {
        st.push(string(1,ch));
        }
        else{
            string operator2=st.top();st.pop();
            string operator1=st.top();st.pop();
            string temp=string(1,ch)+operator1+operator2;
            st.push(temp);
        }
       }
       return st.top();
    }
};
int main()
{
    string m;
    cout<<"enter expression"<<endl;
    cin>>m;
    Solution s;
    s.postfixToPrefix(m);
}