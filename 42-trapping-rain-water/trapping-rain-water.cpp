class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0;
        int leftmax = 0;
        int rightmax = 0;
        int left = 0;
        int right = height.size()-1;
        while(left<right){
            leftmax = max(leftmax,height[left]);
            rightmax = max(rightmax,height[right]);
            if(leftmax<rightmax){
                ans+= (leftmax-height[left]);
                left++;
            }
            else{
                ans+=(rightmax-height[right]);
                right--;

            }
        }
        return ans;
    }
};