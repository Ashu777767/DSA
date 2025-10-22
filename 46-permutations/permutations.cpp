class Solution {
public:
void Allpermutations(vector<int>& nums, vector<vector<int>>& ans,int idx)
{
    if(idx>=nums.size())   //base case
    {
        ans.push_back({nums});
        return ;
    }

    for(int i = idx;i<nums.size();i++)
    {
        swap(nums[idx],nums[i]);
        Allpermutations(nums,ans,idx+1);
        swap(nums[idx],nums[i]);  //backtrack
    }
}

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        int idx = 0;
        Allpermutations(nums,ans,idx);
        return ans;
    }
};