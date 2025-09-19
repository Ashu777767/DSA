class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size();
	vector<int>rightSuff(n);
	rightSuff[n-1] = nums[n-1];
	for(int i = n-2;i>=0;i--){
	    rightSuff[i] = rightSuff[i+1]*nums[i];
	}
   vector<int>ans;
   int left = 1;
   for(int i = 0;i<n-1;i++)
   {
       int val = left*rightSuff[i+1];
       ans.push_back(val);
       
       left*=nums[i];
   }
    ans.push_back(left);
      
      return ans;
    }
};