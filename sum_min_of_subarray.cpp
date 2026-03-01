#include<iostream>
using namespace std;
#include<stack>
class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {

        int n = arr.size();
        const int MOD = 1e9 + 7;

        vector<int> ple(n), nle(n);
        stack<int> st;

        // -------- Previous Smaller --------
        for(int i = 0; i < n; i++) {

            while(!st.empty() && arr[st.top()] > arr[i])
                st.pop();

            if(st.empty())
                ple[i] = -1;
            else
                ple[i] = st.top();

            st.push(i);
        }

        while(!st.empty()) st.pop();

        // -------- Next Smaller --------
        for(int i = n-1; i >= 0; i--) {

            while(!st.empty() && arr[st.top()] >= arr[i])
                st.pop();

            if(st.empty())
                nle[i] =n;
            else
                nle[i] = st.top();

            st.push(i);
        }

        long long sum = 0;

        for(int i = 0; i < n; i++) {
            long long left  = i - ple[i];
            long long right = nle[i] - i;

            sum = (sum + arr[i] * left * right) % MOD;
        }

        return sum;
    }
};