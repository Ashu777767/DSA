class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n; 
        auto reverse = [](vector<int>& arr, int start, int end) {
            while (start < end) {
                swap(arr[start++], arr[end--]);
            }
        };

        reverse(nums, 0, n - 1);     // Step 1: Reverse whole array
        reverse(nums, 0, k - 1);     // Step 2: Reverse first k elements
        reverse(nums, k, n - 1);     // Step 3: Reverse the rest
    }
};
