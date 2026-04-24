class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, vector<long long>> mp;

        // Step 1: store indices
        for (int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }

        vector<long long> ans(n);

        // Step 2: process each group
        for (auto& it : mp) {
            vector<long long>& v = it.second;
            int m = v.size();

            // total sum of indices
            long long total = 0;
            for (long long x : v)
                total += x;

            long long prefix = 0;

            for (int i = 0; i < m; i++) {
                long long curr = v[i];

                // LEFT + RIGHT
                long long left = curr * i - prefix;
                long long right = (total - prefix - curr) - curr * (m - i - 1);

                ans[curr] = left + right;

                prefix += curr;
            }
        }

        return ans;
    }
};