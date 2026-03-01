#include<iostream>
#include<stack>
using namespace std;
// class Solution {
// public:
//     vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
//         stack<int>st;
//         vector<int>ans(nums1.size(),-1);
//         for(int d:nums2)
//         {   
//             st.push(d);
//         }
//         for(int i=0;i<nums1.size();i++)
//         {
//             while(st.top()!=nums1[i])
//             {
//                 if(st.top()>nums1[i])
//                 {
//                     ans[i]=st.top();
//                     st.pop();
//                 }
//                 else
//                 {
//                     st.pop();
//                 }
                
//             }
//             for(int d:nums2)
//         {   
//             st.push(d);
//         }
//         }
//         return ans;
        
//     }
// };
// class Solution {
// public:
//     vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
//         stack<int>st;
//         vector<int>ans(nums1.size(),-1);
//         for(int i=0;i<nums1.size();i++)
//         {
//             int j=nums2.size()-1;
//             while(nums2[j]!=nums1[i])
//             {
//                 if(nums2[j]>nums1[i])
//                 {
//                     st.push(nums2[j]);
//                 }
//                 j--;

//             }
//             if(!st.empty())
//             {
//                 ans[i]=st.top();
//             }
//             st = stack<int>(); 
            
//         }
//         return ans;
        
//     }
// };
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>mpp;
        stack<int>st;
        for(int i=nums2.size()-1;i>=0;i--)
        {
            while(!st.empty()&&st.top()<=nums2[i])
            {
                st.pop();
            }
            if(st.empty())
            {
                mpp[nums2[i]]=-1;
            }
            else
            {
                mpp[nums2[i]]=st.top();
            }
            st.push(nums2[i]);
        }
        vector<int>ans;
        for(int i=0;i<nums1.size();i++)
        {
            ans.push_back(mpp[nums1[i]]);
        }
        return ans;
        
    }
};