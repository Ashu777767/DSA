class Solution {
public:
    void dfs(vector<vector<int>>& isConnected, vector<bool>& vis, int node,
             int n) {
        for (int col = 0; col < n; col++) {
            // If connected and not visited → explore
            if (isConnected[node][col] == 1 && !vis[col]) {
                vis[col] = true;
                dfs(isConnected, vis, col, n);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> vis(n, false);
        int provinces = 0;

        // Traverse each city
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                vis[i] = true;
                dfs(isConnected, vis, i, n);
                provinces++;
            }
        }

        return provinces;
    }
};