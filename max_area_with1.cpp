#include<iostream>
using namespace std;
class Solution {
public:

    int findingarea(vector<int>& height)
    {
        int n = height.size();
        stack<int> st;
        vector<int> pse(n), nse(n);

        // Previous Smaller
        for(int i = 0; i < n; i++)
        {
            while(!st.empty() && height[st.top()] >= height[i])
                st.pop();

            if(st.empty())
                pse[i] = -1;
            else
                pse[i] = st.top();

            st.push(i);
        }

        while(!st.empty()) st.pop();

        // Next Smaller
        for(int i = n-1; i >= 0; i--)
        {
            while(!st.empty() && height[st.top()] >= height[i])
                st.pop();

            if(st.empty())
                nse[i] = n;
            else
                nse[i] = st.top();

            st.push(i);
        }

        int maxarea = 0;

        for(int i = 0; i < n; i++)
        {
            int width = nse[i] - pse[i] - 1;
            int area = height[i] * width;
            maxarea = max(maxarea, area);
        }

        return maxarea;
    }


    int maximalRectangle(vector<vector<char>>& matrix) {

        int m = matrix.size();
        int n = matrix[0].size();

        vector<int> height(n,0);
        int maxarea = 0;

        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(matrix[i][j] == '1')
                    height[j]++;
                else
                    height[j] = 0;
            }

            int area = findingarea(height);
            maxarea = max(maxarea, area);
        }

        return maxarea;
    }
};