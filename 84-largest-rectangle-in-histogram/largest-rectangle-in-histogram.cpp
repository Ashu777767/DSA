class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
           int n = heights.size();
        vector<int> right(n), left(n);
        stack<int> s;

        // NSR
        for (int i = n - 1; i >= 0; i--) {
            while (!s.empty() && heights[s.top()] >= heights[i]) {
                s.pop();
            }
            right[i] = s.empty() ? n : s.top();
            s.push(i);
        }

        while (!s.empty()) s.pop();

        // NSL
        for (int i = 0; i < n; i++) {
            while (!s.empty() && heights[s.top()] >= heights[i]) {
                s.pop();
            }
            left[i] = s.empty() ? -1 : s.top();
            s.push(i);
        }

        // Calculate max area
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int width = right[i] - left[i] - 1;
            ans = max(ans, heights[i] * width);
        }
        return ans;

    }
};