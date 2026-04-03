class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int cnt = 0;
        for(int i = 0;i<nums.size();i++){
            
         if(mp[k-nums[i]]>0){  //t.c 0(n) but space 0(n)
                cnt++;
                mp[k-nums[i]]--;
            }
            else{
            mp[nums[i]]++;
            }
        }
        return cnt;
    }
};