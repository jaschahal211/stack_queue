#include<iostream>
using namespace std;
class Solution
{
public:
    int celebrity(vector<vector<int>> &M){
        stack<int>st;
        for(int i=0;i<M.size();i++)
        {
            st.push(i);
        }
        while(st.size()>1)
        {
            int i=st.top();
            st.pop();
            int j=st.top();
            st.pop();
            if(M[i][j]==1)
            {
                st.push(j);
            }
            else
            {
                st.push(i);
            }
        }
        int celeb=st.top();
        for(int i=0;i<M.size();i++)
        {
            if((i!=celeb)&&(M[i][celeb]==0||M[celeb][i]==1))
            {
                return -1;
            }
        }
        return celeb;
        
    }
};
