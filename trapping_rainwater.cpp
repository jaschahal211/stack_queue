#include<iostream>
using namespace std;
class Solution {
public:
    int trap(vector<int>& height) {
        vector<int>lmax(height.size());
        vector<int>rmax(height.size());
        lmax[0]=height[0];
        rmax[height.size()-1]=height[height.size()-1];
       for(int i=1;i<height.size();i++)
       {
        lmax[i]=max(lmax[i-1],height[i]);
       }
       for(int i=height.size()-2;i>=0;i--)
       {
        rmax[i]=max(rmax[i+1],height[i]);
       }
       int ans=0;
       for(int i=0;i<height.size();i++)
       {
        ans+=min(lmax[i],rmax[i])-height[i];
       }
       return ans;
        
    }
};