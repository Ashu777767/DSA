class Solution {
public:
    int maxArea(vector<int>& height) {
        int h = 0;
        int w = 0;
        int left = 0;
        int right = height.size()-1;
        int  maxvalue = INT_MIN;
        while(left<right)
        {
            h = min(height[left],height[right]);
            w = right-left;
            int area = h*w;
            maxvalue = max(maxvalue,area);
            if(height[left]<height[right]){
                left++;
            }
            else{
                right--;
            }
        }
        return maxvalue;
    }
};