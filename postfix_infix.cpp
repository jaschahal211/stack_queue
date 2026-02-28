#include<iostream>
using namespace std;
#include<string>
#include<stack>
class Solution{
public:
stack<string>st;
    string prefixInfix(string s)
    {
        for(int i=s.size()-1;i>=0;i--)
        {
            char ch=s[i];
            if(isalnum(ch))
            {
                st.push(string(1,ch));
            }
            else{
                string operator1=st.top();st.pop();
                string operator2=st.top();st.pop();
                string temp="("+operator1+string(1,ch)+operator2+")";
                st.push(temp);
            }
        }
return st.top();

    }

};
int main()
{
    string m;
    cout<<"enter string="<<endl;
    cin>>m;
    Solution s;
    s.prefixInfix(m);
}