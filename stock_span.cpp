#include<iostream>
using namespace std;
class Solution
{
    public:
    vector <int> stockSpan(vector<int> arr, int n) {
        //previous high finding for each array element:
        stack<int>st;
        vector<int>phe(arr.size(),0);
        vector<int>ans;
        for(int i=0;i<arr.size();i++)
        {
            while(!st.empty()&&arr[st.top()]<arr[i])
            {
                st.pop();
            }
            if(st.empty())
            {
                phe[i]=-1;
            }
            else
            {
                phe[i]=st.top();
            }
            int left=i-phe[i];
            ans.push_back(left);
            st.push(i);
        }
        return ans;
       
    }
};
