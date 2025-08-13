class Solution {
public:
    int maxArea(vector<int>& height) {
      int min1 = INT_MAX;
      int left = 0;
      int right = height.size()-1;
     int maxvalue = INT_MIN;
     while(left<right)
     {
        int h  = right-left;
        int width = min(height[right],height[left]);
        int area = h*width;
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