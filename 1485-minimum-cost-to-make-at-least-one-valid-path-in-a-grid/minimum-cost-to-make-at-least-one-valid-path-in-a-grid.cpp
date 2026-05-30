class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();

        deque<pair<int,int>> dq;

        vector<vector<int>> dist(r, vector<int>(c, INT_MAX));

        vector<pair<int,int>> dir = {
            {0,1},    // 1 Right
            {0,-1},   // 2 Left
            {1,0},    // 3 Down
            {-1,0}    // 4 Up
        };

        dq.push_front({0,0});
        dist[0][0] = 0;

        while(!dq.empty()) {

            auto [row,col] = dq.front();
            dq.pop_front();

            for(int i=0;i<4;i++) {

                int nrow = row + dir[i].first;
                int ncol = col + dir[i].second;

                if(nrow < 0 || ncol < 0 ||
                   nrow >= r || ncol >= c)
                    continue;

                int wt = (grid[row][col] == i+1) ? 0 : 1;

                if(dist[row][col] + wt < dist[nrow][ncol]) {

                    dist[nrow][ncol] = dist[row][col] + wt;

                    if(wt == 0)
                        dq.push_front({nrow,ncol});
                    else
                        dq.push_back({nrow,ncol});
                }
            }
        }

        return dist[r-1][c-1];
    }
};