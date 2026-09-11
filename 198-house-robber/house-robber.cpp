class Solution {
public:
  int solve(int n,vector<int>&dp,vector<int>& nums){
    if(n == 0){
        return nums[0];
    }
    if(n == 1){
        return max(nums[0],nums[1]);
    }
    if(dp[n] != -1){
        return dp[n];
    }
    dp[n] = max(solve(n-1,dp,nums),solve(n-2,dp,nums)+nums[n]);
    return dp[n];
  }

    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n,-1);
        return solve(n-1,dp,nums);
    }
};