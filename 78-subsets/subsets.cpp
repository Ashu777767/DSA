class Solution {
public:
void solveans(vector<int> nums, vector<vector<int>> &ans,int index,vector<int>output){
    if(index>=nums.size()){
        ans.push_back(output);
        return ;
    }

   
    //include
    output.push_back(nums[index]);
    solveans(nums,ans,index+1,output);

     //exclude
     output.pop_back();
    solveans(nums,ans,index+1,output);

}
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;//powerset
        vector<int>output;
        int index = 0;
        solveans(nums,ans,index,output);
     return ans;
    }
};