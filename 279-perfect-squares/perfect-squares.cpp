class Solution {
public:
    int solve(int n, vector<int>& dp) {

        // Base case
        if (n == 0)
            return 0;

        // Already calculated
        if (dp[n] != -1)
            return dp[n];

        int ans = INT_MAX;

        // Try every perfect square <= n
        for (int j = 1; j * j <= n; j++) {

            int sq = j * j;

            ans = min(ans, solve(n - sq, dp) + 1);
        }

        return dp[n] = ans;
    }

    int numSquares(int n) {

        vector<int> dp(n + 1, -1);

        return solve(n, dp);
    }
};