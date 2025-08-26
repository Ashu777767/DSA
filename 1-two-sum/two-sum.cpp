class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
      unordered_map<int,int>map; // stores value ->index
      for(int i = 0;i<nums.size();i++){
        int check = target - nums[i];
        if(map.find(check) != map.end()){
            return {map[check],i};
        }
        map[nums[i]] = i;
      }
     return {};   
    }
};