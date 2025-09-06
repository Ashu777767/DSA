class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0;
        int left = 0;
        int right = height.size()-1;
        int leftmax = INT_MIN;
        int rightmax = INT_MIN;
        while(left<right){
             leftmax = max(leftmax,height[left]);     //max left border as per current bar
             rightmax = max(rightmax,height[right]);   //max right border as per current bar
             if(leftmax<rightmax){                  //min(leftmax,rightmax)-height[i]  formula
                ans+=(leftmax-height[left]);
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