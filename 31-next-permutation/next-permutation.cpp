class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        //step 1 finding break point
        int n = nums.size();
         int idx = -1;
         
        for(int i = n-2;i>=0;i--){
            if(nums[i]<nums[i+1])
            {
               idx = i;
               break;
            }
        }
        //step 2 : swap with next greater
        if(idx != -1){ // if breakpoint exists
    for(int i = n-1; i>idx; i--){
        if(nums[i] > nums[idx]){
            swap(nums[i], nums[idx]);
            break;
        }
    }
}

        //step 3 : reverse
        if(idx == -1)
       reverse(nums.begin(), nums.end());
     else
    reverse(nums.begin()+idx+1, nums.end());

    }
};