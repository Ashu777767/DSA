class Solution {
public:
    void dfs(int i, int j, vector<vector<char>>& grid, int n, int m) {
        if (i < 0 || j < 0 || i >= n || j >= m || grid[i][j] == '0')
            return; // base case

        grid[i][j] = '0';
        dfs(i - 1, j, grid, n, m); // top
        dfs(i + 1, j, grid, n, m); // bottom
        dfs(i, j - 1, grid, n, m); // left
        dfs(i, j + 1, grid, n, m); // right
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int Island = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1') {
                    Island++;
                    dfs(i, j, grid, n, m);
                }
            }
        }
        return Island;
    }
};