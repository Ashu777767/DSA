class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] == 1 || grid[n-1][n-1] == 1)
            return -1;
        queue<pair<pair<int, int>, int>> q;
        q.push({{0, 0}, 1});
        grid[0][0] = 1;
        vector<pair<int, int>> dir = {
            {-1, 0}, // up
            {1, 0},  // down
            {0, -1}, // left
            {0, 1},  // right

            {-1, -1}, // top-left
            {-1, 1},  // top-right
            {1, -1},  // bottom-left
            {1, 1}    // bottom-right
        };
        int ans = -1;
        while (!q.empty()) {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int dist = q.front().second;
            q.pop();
            if(row == n-1 &&  col == n-1){
                ans= dist;
                break;
            }
            for (auto& it : dir) {
                int nrow = row + it.first;
                int ncol = col + it.second;
                if (nrow < 0 || ncol < 0 || nrow >= n || ncol >= n ||
                    grid[nrow][ncol] == 1) {
                    continue;
                }else{
                    q.push({{nrow,ncol},dist+1});
                    grid[nrow][ncol] = 1;
                }
                
            }
        }
        return ans;
    }
};