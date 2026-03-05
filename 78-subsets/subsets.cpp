class Solution {
public:
  void printsubset(int idx,vector<vector<int>>& ans,vector<int>& curr,vector<int>& nums){
    if(idx == nums.size()){
        ans.push_back(curr);
        return ;
    }
    curr.push_back(nums[idx]);//recurion d0
    printsubset(idx+1,ans,curr,nums);
    //undo backtrack
    curr.pop_back();
    printsubset(idx+1,ans,curr,nums);

  }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>curr;
        printsubset(0,ans,curr,nums);
        return ans;

    }
};