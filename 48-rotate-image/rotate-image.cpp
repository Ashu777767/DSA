class Solution {
public:
void reverse( vector<vector<int>>& matrix,int e,int r){
    int s = 0;
    while(s<e){
        swap(matrix[r][s++],matrix[r][e--]);
    }
}
    void rotate(vector<vector<int>>& matrix) {
        int rowsize = matrix.size();
        int colsize = matrix[0].size();
        for(int i = 0;i<rowsize;i++){
        for(int j = i;j<colsize;j++){
        swap(matrix[i][j],matrix[j][i]);
    }
 }
 for(int r = 0;r<rowsize;r++){
 reverse(matrix,colsize-1,r);
 }
    }
};