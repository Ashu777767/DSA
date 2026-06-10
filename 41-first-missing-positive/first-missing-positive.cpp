class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_set<int>s;
        int n = nums.size();
       
        for(int i = 0;i<n;i++){
            s.insert(nums[i]);
        }
        int ans;
        for(int i = 1;i<=n;i++){
            if(!s.count(i)){
                ans = i;
               return ans;
            }
        }
        return n+1;
    }
};