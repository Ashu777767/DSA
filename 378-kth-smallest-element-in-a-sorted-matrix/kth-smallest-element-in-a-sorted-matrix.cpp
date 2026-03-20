class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int row = 0;
        int col =0;
        priority_queue<int>pq;
        while(row<n){
          pq.push(matrix[row][col]);
          if(pq.size()>k){
            pq.pop();
          }
          col++;
          if(col == n){
            row++;
            col = 0;
          }
        }
        return pq.top();
    }
};