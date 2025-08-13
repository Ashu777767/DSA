class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0;
        int j = i+1;
        int n = nums.size();
        while(i<n-1 &&j<n){
            if(nums[i] == 0){
             if(nums[j]!=0){
                swap(nums[i++],nums[j++]);
             }
             else{
                j++;
             }
            }
            else{
                i++;
                j = i+1;
            }
        }
    }
};