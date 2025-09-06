class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int>leftborder(n,0);
        vector<int>rightborder(n,0);
        leftborder[0] = height[0];
        rightborder[n-1] = height[n-1];
        for(int i = 1;i<n;i++){
            leftborder[i] = max(leftborder[i-1],height[i]);
        }
        for(int i = n-2;i>=0;i--){
            rightborder[i] = max(rightborder[i+1],height[i]);
        }
        int ans = 0;
        for(int i = 0;i<n;i++){
            ans+= (min(leftborder[i],rightborder[i])-height[i]);
        }
        return ans;
    }
};