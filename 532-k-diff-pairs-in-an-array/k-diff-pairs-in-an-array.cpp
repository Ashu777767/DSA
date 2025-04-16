class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        //ashucode
        if (k < 0) return 0; 

        sort(nums.begin(), nums.end());
        int n = nums.size();
        set<pair<int, int>> uniquePairs;

        for (int i = 0; i < n; ++i) {
            int target = nums[i] + k;

            if (binary_search(nums.begin() + i + 1, nums.end(), target)) {
                uniquePairs.insert({nums[i], target});
            }
        }

        return uniquePairs.size();
    }
};