class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size();

        unordered_map<string, int> mp;

        // store rows
        for (auto row : grid) {
            string s = "";
            for (int x : row) {
                s += to_string(x) + "#";
            }
            mp[s]++;
        }

        int count = 0;

        // check columns
        for (int j = 0; j < n; j++) {
            string s = "";
            for (int i = 0; i < n; i++) {
                s += to_string(grid[i][j]) + "#";
            }
            count += mp[s];
        }

        return count;
    }
};