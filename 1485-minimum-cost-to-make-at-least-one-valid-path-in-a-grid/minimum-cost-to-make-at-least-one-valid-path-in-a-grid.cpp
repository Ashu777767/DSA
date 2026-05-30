class Solution {
public:
 bool isvalid(int row ,int col,int r,int c){
     if(row<0 || col<0 || row>=r || col>=c){
         return false;
     }
     return true;
 }
    int minCost(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            pq;
        vector<vector<bool>> vis(r, vector<bool>(c, 0));
        pq.push({0, {0, 0}});//cost,row,col
        vector<pair<int, int>> direction = {
            {-1, 0}, // Up
            {0, 1},  // Right
            {1, 0},  // Down
            {0, -1}  // Left
        };
        
        while(!pq.empty()){
           int cost = pq.top().first;
           int row = pq.top().second.first;
           int col = pq.top().second.second;
           pq.pop();
           if(vis[row][col]) continue;
           vis[row][col] = true;
           if(row == r-1 && col == c-1){
            return cost;
           }
           bool flag = false;
           for(auto &dir:direction){
            int nrow = row-dir.first;
            int ncol = col-dir.second;
            if(nrow<0 || ncol<0 || nrow>=r || ncol>=c) continue;
            int pathdir = grid[row][col];
            if(!flag && pathdir == 1 && isvalid(row,col+1,r,c) && (row == nrow && col+1 == ncol)){
                 pq.push({cost,{row,col+1}});
                 flag = true;
                 continue;
            }else if(!flag && pathdir == 2 && isvalid(row,col-1,r,c) && (row == nrow && col-1 == ncol)){
                 pq.push({cost,{row,col-1}});
                 flag = true;
                 continue;
            }else if(!flag && pathdir == 3 && isvalid(row+1,col,r,c) && (row+1 == nrow && col == ncol)){
                 pq.push({cost,{row+1,col}});
                 flag = true;
                 continue;
            }else if(!flag && pathdir == 4 && isvalid(row-1,col,r,c) && (row-1 == nrow && col == ncol)){
                 pq.push({cost,{row-1,col}});
                 flag = true;
                 continue;
            }else{
                pq.push({cost+1,{nrow,ncol}});
            }
            

           }
        }
        return 0;
    }
};