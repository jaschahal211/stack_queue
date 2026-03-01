#include<iostream>
#include<string>
#include<stack>
using namespace std;
 class Solution {
public:
    string prefixToPostfix(const string& s) {
        stack<string>st;
       for(int i=s.size()-1;i>=0;i--)
       {
        char ch=s[i];
        if(isalnum(ch))
        {
        st.push(string(1,ch));
        }
        else{
            string operator2=st.top();st.pop();
            string operator1=st.top();st.pop();
            string temp=operator1+operator2+string(1,ch);
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
    s.prefixToPostfix(m);
}