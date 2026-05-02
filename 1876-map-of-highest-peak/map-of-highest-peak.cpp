class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& mat) {
        int rows = mat.size();
        int cols = mat[0].size();

        // Distance matrix (answer)
        vector<vector<int>> distance(rows, vector<int>(cols, INT_MAX));

        // Queue for BFS
        queue<pair<int, int>> q;

        // Step 1: Push all 0s into queue (multi-source)
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (mat[r][c] == 1) {
                    distance[r][c] = 0;
                    q.push({r, c});
                }
            }
        }

        // Directions: up, down, left, right
        vector<pair<int,int>> directions = {
            {-1, 0}, {1, 0}, {0, -1}, {0, 1}
        };

        // Step 2: BFS traversal
        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            for (auto [dr, dc] : directions) {
                int newRow = r + dr;
                int newCol = c + dc;

                // Check boundaries
                if (newRow < 0 || newCol < 0 || newRow >= rows || newCol >= cols)
                    continue;

                // Relaxation (important step)
                if (distance[newRow][newCol] > distance[r][c] + 1) {
                    distance[newRow][newCol] = distance[r][c] + 1;
                    q.push({newRow, newCol});
                }
            }
        }

        return distance;
    }
};