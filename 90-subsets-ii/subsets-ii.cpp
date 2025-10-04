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
     int idx = index+1;
     while(idx<nums.size() && nums[idx] == nums[idx-1]){    //this is the main skkiping case
        idx++;
     }
    solveans(nums,ans,idx,output);

}
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;//powerset
        vector<int>output;
        int index = 0;
        solveans(nums,ans,index,output);
     return ans;
    }
};