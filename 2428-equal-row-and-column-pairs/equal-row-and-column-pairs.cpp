class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size();

        map<vector<int>, int> mp;

        // store rows
        for (auto row : grid) {
            mp[row]++;
        }

        int count = 0;

        // check columns
        for (int j = 0; j < n; j++) {
            vector<int> col;

            for (int i = 0; i < n; i++) {
                col.push_back(grid[i][j]);
            }

            count += mp[col];
        }

        return count;
    }
};