class Solution {
public:
 void findsubsets(vector<int>& nums, vector<vector<int>>& ans,vector<int>& result,int idx)
 {
    if(idx >= nums.size()) //base case
    {
        ans.push_back({result});  //O(2^n)
        return ;
    }
    //include
    result.push_back(nums[idx]);
    findsubsets(nums,ans,result,idx+1);
    //exclude
    result.pop_back();
    idx++;
    while(idx<nums.size() && nums[idx-1] == nums[idx]){  //check for duplicate
        idx++;
    }
    findsubsets(nums,ans,result,idx);

 }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        vector<int>result;
        int idx = 0;
        findsubsets(nums,ans,result,idx);
        return ans;
    }
};