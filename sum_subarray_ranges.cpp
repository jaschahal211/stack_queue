#include<iostream>
using namespace std;
#include<stack>
class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        
        int n = nums.size();
        
        vector<int> nextsmaller(n), nextgreater(n);
        vector<int> previoussmaller(n), previousgreater(n);
        
        long long minsum = 0, maxsum = 0;
        stack<int> st;

        // -------- Previous Smaller --------
        for(int i = 0; i < n; i++) {
            while(!st.empty() && nums[st.top()] >= nums[i]) {
                st.pop();
            }
            previoussmaller[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        while(!st.empty()) st.pop();

        // -------- Next Smaller --------
        for(int i = n - 1; i >= 0; i--) {
            while(!st.empty() && nums[st.top()] > nums[i]) {
                st.pop();
            }
            nextsmaller[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        while(!st.empty()) st.pop();

        // -------- Calculate Min Contribution --------
        for(int i = 0; i < n; i++) {
            long long left = i - previoussmaller[i];
            long long right = nextsmaller[i] - i;
            minsum += (long long)nums[i] * left * right;
        }

        // -------- Previous Greater --------
        for(int i = 0; i < n; i++) {
            while(!st.empty() && nums[st.top()] <= nums[i]) {
                st.pop();
            }
            previousgreater[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        while(!st.empty()) st.pop();

        // -------- Next Greater --------
        for(int i = n - 1; i >= 0; i--) {
            while(!st.empty() && nums[st.top()] < nums[i]) {
                st.pop();
            }
            nextgreater[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        // -------- Calculate Max Contribution --------
        for(int i = 0; i < n; i++) {
            long long left = i - previousgreater[i];
            long long right = nextgreater[i] - i;
            maxsum += (long long)nums[i] * left * right;
        }

        return maxsum - minsum;
    }
};