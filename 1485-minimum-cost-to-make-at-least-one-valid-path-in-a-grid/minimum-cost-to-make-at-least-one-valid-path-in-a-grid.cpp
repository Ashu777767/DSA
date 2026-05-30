class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();

        deque<pair<int, pair<int, int>>> dq;

        vector<vector<bool>> vis(r, vector<bool>(c, 0));

        dq.push_front({0, {0, 0}}); // cost,row,col

        vector<pair<int, int>> direction = {
            {-1, 0}, // Up
            {0, 1},  // Right
            {1, 0},  // Down
            {0, -1}  // Left
        };

        while (!dq.empty()) {
            int cost = dq.front().first;
            int row = dq.front().second.first;
            int col = dq.front().second.second;
            dq.pop_front();

            if (vis[row][col])
                continue;

            vis[row][col] = true;

            if (row == r - 1 && col == c - 1) {
                return cost;
            }

            bool flag = false;

            for (auto& dir : direction) {
                int nrow = row + dir.first;
                int ncol = col + dir.second;

                if (nrow < 0 || ncol < 0 || nrow >= r || ncol >= c)
                    continue;

                int pathdir = grid[row][col];

                if (!flag && pathdir == 1 &&
                    (row == nrow && col + 1 == ncol)) {

                    dq.push_front({cost, {nrow, ncol}});
                    flag = true;
                    continue;

                } else if (!flag && pathdir == 2 &&
                           (row == nrow && col - 1 == ncol)) {

                    dq.push_front({cost, {nrow, ncol}});
                    flag = true;
                    continue;

                } else if (!flag && pathdir == 3 &&
                           (row + 1 == nrow && col == ncol)) {

                    dq.push_front({cost, {nrow, ncol}});
                    flag = true;
                    continue;

                } else if (!flag && pathdir == 4 &&
                           (row - 1 == nrow && col == ncol)) {

                    dq.push_front({cost, {nrow, ncol}});
                    flag = true;
                    continue;

                } else {

                    dq.push_back({cost + 1, {nrow, ncol}});
                }
            }
        }

        return 0;
    }
};