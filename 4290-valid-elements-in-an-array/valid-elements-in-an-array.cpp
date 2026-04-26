class Solution {
public:
    vector<int> findValidElements(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        int leftmax = nums[0];

        ans.push_back(leftmax);
        // rightsuffix
        vector<int> right(n);
        right[n - 1] = nums[n - 1];

        for (int i = n - 2; i >= 0; i--) {
            right[i] = right[i + 1] > nums[i] ? right[i+1] : nums[i];
        }
        for (int i = 1; i < nums.size() - 1; i++) {
            if (nums[i] > leftmax || nums[i] > right[i + 1]) {
                ans.push_back(nums[i]);
            }
            leftmax = nums[i] > leftmax ? nums[i]:leftmax;
        }
        if(n>1)
        ans.push_back(nums[n - 1]);
        return ans;
    }
};