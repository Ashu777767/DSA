class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();

        // {nums2, nums1}
        vector<pair<int, int>> v;

        for (int i = 0; i < n; i++) {
            v.push_back({nums2[i], nums1[i]});
        }

        // Sort by nums2 in descending order
        sort(v.rbegin(), v.rend());

        // Min-heap to keep the largest k nums1 values
        priority_queue<int, vector<int>, greater<int>> pq;

        long long sum = 0;
        long long ans = 0;

        for (int i = 0; i < n; i++) {

            // Add current nums1
            pq.push(v[i].second);
            sum += v[i].second;

            // Keep only k largest nums1 values
            if (pq.size() > k) {
                sum -= pq.top();
                pq.pop();
            }

            // Calculate score when we have exactly k elements
            if (pq.size() == k) {
                ans = max(ans, sum * v[i].first);
            }
        }

        return ans;
    }
};