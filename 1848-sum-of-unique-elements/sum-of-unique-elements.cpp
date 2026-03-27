class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        unordered_map<int,int>mp;
        int sum = 0;
        for(int val:nums){
            mp[val]++;
        }
        for(int val:nums){
            if(mp[val]==1){
                sum+=val;
                
            }
        }
        return sum;
    }
};