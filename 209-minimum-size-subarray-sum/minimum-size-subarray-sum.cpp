class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0;
        int sum = 0;
        int len;
        int minValue = INT_MAX;
        for(int right = 0;right<nums.size();right++){
            sum+=nums[right];
            while(sum>=target){
                 len = right-left+1;
                minValue = min(minValue,len);
                sum-=nums[left];
                left++;
            }
        }
        if(minValue == INT_MAX){
            return 0;
        }
      return minValue;
            
            
    }
};