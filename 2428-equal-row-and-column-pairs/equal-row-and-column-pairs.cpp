class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        map<int,vector<int>>rows;
        map<int,vector<int>>cols;
        for(int i = 0;i<grid.size();i++){
            for(int j = 0;j<grid[0].size();j++){
                rows[i].push_back(grid[i][j]);
                cols[i].push_back(grid[j][i]);
            }
        }
        int count = 0;
        for(int i = 0;i<grid.size();i++){
            for(int j = 0;j<grid.size();j++){
            if(rows[i] == cols[j]){
                count++;
            }
            }
        }
        return count;
    }
};