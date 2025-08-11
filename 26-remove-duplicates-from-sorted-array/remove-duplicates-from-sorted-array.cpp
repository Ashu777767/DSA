class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        for(int i = 1;i<n;i++)
        {
             if(nums[i] == nums[i-1])
             {
                nums[i-1] = INT_MAX;
             }
        }
        sort(nums.begin(),nums.end());
        int k = 0;
        for(int i =0;i<n;i++){
            if(nums[i] != INT_MAX){
                k++;
            }
        }
        return k;
    }
};