class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        vector<int>ans(n,pivot);
        int st= 0,end = n-1;
        for(int i = 0,j= n-1;i<n,j>=0;i++,j--){
            if(nums[i]<pivot) ans[st++] = nums[i];
            if(nums[j]>pivot)ans[end--] = nums[j];
        }
        return ans;
    }
};