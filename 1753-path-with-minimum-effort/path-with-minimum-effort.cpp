class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int r = heights.size();
        int c = heights[0].size();
        vector<vector<bool>> vis(r, vector<bool>(c, false));
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            pq;
        vector<pair<int, int>> directions = {
            {-1, 0}, // Up
            {0, 1},  // Right
            {1, 0},  // Down
            {0, -1}  // Left
        };
        pq.push({0, {0, 0}}); // maxeffrot,row,col;
        while (!pq.empty()) {
            int maxeffort = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            pq.pop();
            if (vis[row][col]) continue;
            vis[row][col] = true;
            if(row == r-1 && col == c-1) return maxeffort;
            for(auto & dir:directions){
                int nrow = row + dir.first;
                int ncol = col+dir.second;
                if(nrow<0 || ncol<0 || nrow>=r || ncol>=c || vis[nrow][ncol]) continue;
                int diff = abs(heights[nrow][ncol]-heights[row][col]);
                if(diff>maxeffort){
                    pq.push({diff,{nrow,ncol}});
                }else{
                    pq.push({maxeffort,{nrow,ncol}});
                }
            }
            
        }

        return 0;
    }
};