class Solution {
public:
int solve(int st,int en,vector<int>&nums){
    int size = en-st+1;
   if(size == 1){
    return nums[st];
}
    if(size == 2){
        return max(nums[st],nums[st+1]);
    }
    int prev1 = nums[st];
    int prev2 = max(nums[st],nums[st+1]);
    st+=2;
    while(st<=en){
        int currLoot = max(prev2,prev1+nums[st]);
        prev1 = prev2;
        prev2 = currLoot;
        st++;
    }
    return prev2;
}


    int rob(vector<int>& nums) {
        int n = nums.size();
         if(n == 1){
        return nums[0];
    }
        return max(solve(0,n-2,nums),solve(1,n-1,nums));
    }
};