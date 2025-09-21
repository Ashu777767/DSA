class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans;
        for(auto val:nums){
            ans.push_back(val);
        }
        nums[n-1] = ans[n-1];
	for(int i = n-2;i>=0;i--){ //make a suffix array of the   given array
	    nums[i] = nums[i+1]*ans[i];
	}
    int left = 1;  //left product
   for(int i = 0;i<n-1;i++)
   {
       int val = left*nums[i+1];
       left*=ans[i];
       ans[i] = val;
   }
    ans[n-1] = left;
      
      return ans;
        
    }
};