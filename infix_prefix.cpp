#include<iostream>
using namespace std;
#include<stack>
#include<string>
class Solution{
public:
    string infixPrefix(string s)
    {
       reverse(s.begin(),s.end());
       string newstring=swapping(s);
       string postfixstring=toPostfix(newstring);
       reverse(postfixstring.begin(),postfixstring.end());
       return postfixstring;
    }
   string swapping(string s)
{
    for(int i = 0; i < s.length(); i++){
        if(s[i] == '(')
            s[i] = ')';
        else if(s[i] == ')')
            s[i] = '(';
    }
    return s;
}
    string toPostfix(string s)
    {
        stack<char>st;
        string output="";
        for(char ch:s)
        {
            if(isalnum(ch))
            {
                output+=ch;
            }
            else if(ch=='(')
            {
                st.push(ch);
            }
            else if(ch==')')
            {
                while(!st.empty()&&st.top()!='(')
                {
                    output+=st.top();
                    st.pop();
                }
                st.pop();
            }
            else{
                while((!st.empty()&&st.top()!='(')&&((precedence(st.top())>precedence(ch))||((precedence(st.top())==precedence(ch))&&ch!='^')))
                {
                    output+=st.top();
                    st.pop();
                }
                st.push(ch);

            }
        }
        while(!st.empty())
                {
                    output+=st.top();
                    st.pop();
                }
        return output;
    }
    int precedence(char ch)
    {
        if(ch=='^'){return 3;}
        else if(ch=='*'||ch=='/'){return 2;}
        else if(ch=='+'||ch=='-'){return 1;}
        else{return -1;}
    }

};
int main()
{
    string m;
    cout<<"enter string"<<endl;
    cin>>m;
    Solution s;
    s.infixPrefix(m);
}