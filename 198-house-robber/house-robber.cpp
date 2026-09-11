class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        if(n == 2) return max(nums[0],nums[1]);
        int prev1 = nums[0];
        int prev2 = max(nums[0],nums[1]);
        int i = 2;
        
        while(i<n){
            int currLoot = max(prev2,prev1+nums[i]);
            prev1 = prev2;
            prev2 = currLoot;
            i++;
        }
        return prev2;
    }
};