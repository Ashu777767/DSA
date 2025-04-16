class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //ashu
        int n = nums.size();
        for(int i = 0;i<n-1;i++){
            for(int j = 1+i;j<n;j++){
                if(nums[i]+nums[j] == target){
                    return {i,j};

                }
            }
        }
        return {};
    }
};