class Solution {
public:
    long long minOperations(vector<int>& nums) {
        long long x = 0;
        long long leftmax = nums[0];
    for(int i = 0;i<nums.size();i++){
      bool flag = false;
        if((nums[i]+x)<leftmax){
            x = leftmax -nums[i];
            nums[i]+=x;
            flag = true;
            
        }
        if(flag)
        leftmax = max((long long)nums[i], leftmax);
        else{
             leftmax = max(((long long)nums[i]+x), leftmax);
        }
    }
        return x;
    }
};