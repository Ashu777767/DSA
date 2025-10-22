class Solution {
public:
 void findsubsets(vector<int>& nums, vector<vector<int>>& ans,vector<int>& result,int idx)
 {
    if(idx >= nums.size()) //base case
    {
        ans.push_back({result});
        return ;
    }
    //include
    result.push_back(nums[idx]);
    findsubsets(nums,ans,result,idx+1);
    //exclude
    result.pop_back();
    findsubsets(nums,ans,result,idx+1);

 }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>result;
        int idx = 0;
        findsubsets(nums,ans,result,idx);
        return ans;
    }
};