class Solution {
public:
    void sortColors(vector<int>& nums) {
       int n = nums.size();
       int st = 0,iterator = 0,end = n-1;  
       while(iterator<=end){
        if(nums[iterator] == 0){
            swap(nums[st],nums[iterator]);
            st++;
            iterator++;
        }else if(nums[iterator] == 1){
            iterator++;
        }else{
            swap(nums[end],nums[iterator]);
            end--;
        }
       }
    }
};