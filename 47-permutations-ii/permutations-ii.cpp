class Solution {
public:
void permutations(vector<vector<int>>&ans,vector<int>&temp,vector<bool>& used,vector<int>& nums)
{
    if(nums.size() == temp.size()){
        ans.push_back(temp);
        return ;
    }
    for(int i = 0;i<nums.size();i++){
        if(used[i] == true) continue;
        if(i>0 && nums[i] == nums[i-1] && !used[i-1]) continue;
        used[i] = true;
        temp.push_back(nums[i]);
        permutations(ans,temp,used,nums);
        temp.pop_back();
        used[i] = false;
    }
}
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        vector<int>temp;
        vector<bool>used(nums.size(), false);
        permutations(ans,temp,used,nums);
        return ans;
    }
};