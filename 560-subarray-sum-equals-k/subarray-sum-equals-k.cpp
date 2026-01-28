class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
      int n  = nums.size();
      int count = 0;
      vector<int>prefix(n);
      prefix[0] = nums[0];
      for(int i = 1;i<n;i++){
        prefix[i] = prefix[i-1]+nums[i];
      }
      unordered_map<int,int>mp;
      for(int i = 0;i<n;i++){
        int val = prefix[i] - k;
        if(prefix[i] == k){
           count++;
        }
        if(mp.find(val)!= mp.end()){
            count+=mp[val];
        }
        mp[prefix[i]]++;
      }
      return count;
    }
};