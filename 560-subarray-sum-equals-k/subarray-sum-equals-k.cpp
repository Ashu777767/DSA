class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
      vector<int>p(n,0);
      int count = 0;
      int val;
      p[0] = nums[0];
      for(int i = 1;i<n;i++){
        p[i] = p[i-1]+nums[i];
      }
      unordered_map<int,int>map;
      for(int j = 0;j<n;j++){
        if(p[j] == k)
        count++;
        val = p[j] - k;
        if(map.find(val)!=map.end()){
            count+=map[val];
        }
      if(map.find(p[j]) == map.end()){
       map[p[j]] = 0;
      }
     map[p[j]]++;
      }
      return count;
    }
};