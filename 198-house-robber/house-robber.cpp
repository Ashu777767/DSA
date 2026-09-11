class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        if(n == 2) return max(nums[0],nums[1]);
        vector<int>dp(n);
        int i = 2;
        dp[0] = nums[0];
        dp[1] = max(nums[0],nums[1]);
        while(i<n){
            dp[i] = max(dp[i-1],dp[i-2]+nums[i]);
            i++;
        }
        return dp[n-1];
    }
};