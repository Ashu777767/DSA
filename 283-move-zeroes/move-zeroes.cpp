class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0;
        int n = nums.size();
        int k = 0;
        while(i<n){
            if(nums[i] != 0){
                nums[k++] = nums[i++];
            }
            else{
                i++;
            }
        }
        while(k<n){
            nums[k] = 0;
            k++;
        }
    }
};