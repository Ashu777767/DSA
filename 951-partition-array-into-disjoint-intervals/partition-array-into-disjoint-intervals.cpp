class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int n = nums.size();
        int leftMax = nums[0];
        int maxSeen = nums[0];
        int pos = 0;

        for (int i = 1; i < n; i++) {
            if (nums[i] < leftMax) {
                // Must include i in left → extend
                pos = i;
            leftMax = maxSeen; // update leftMax to current maxSeen
            } 
            else maxSeen = max(maxSeen, nums[i]);  
        }

        return pos + 1;
    }
};