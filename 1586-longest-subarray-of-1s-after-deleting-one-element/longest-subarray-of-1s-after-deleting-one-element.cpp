class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int left = 0;
        int deleteCount = 0;
        int maxValue = INT_MIN;
        for(int right = 0;right<nums.size();right++)
        { 
            if(nums[right]  == 0)
            {
                deleteCount++;
            }
            while(deleteCount>1){
            if(nums[left] == 0)
            deleteCount--;
            left++;
            }

            maxValue = max(maxValue,(right-left));
        }
        if(maxValue == INT_MIN){
            return 0;
        }
        return maxValue;
    }
};