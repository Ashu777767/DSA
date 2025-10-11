class Solution {
public:
bool isSafe(vector<vector<char>>& board,int row,int col,char dig)
{
    //horizontal check
    for(int j = 0;j<9;j++){
        if(board[row][j] == dig){
            return false;
        }
    }
    //vertical check
    for(int j = 0;j<9;j++){
        if(board[j][col] == dig){
            return false;
        }
    }
    //grid check
    int strow = (row/3)*3;
    int stcol = (col/3)*3;
    for(int i = strow;i<=strow+2;i++){
        for(int j = stcol;j<=stcol+2;j++){
            if(board[i][j] == dig){
                return false;
            }
        }
    }
    return true;
}
bool helper(vector<vector<char>>& board,int row ,int col)
{
    if(row == 9)
    {
        return true;
    }
    int nextrow = row,nextcol = col+1;
    if(col == 9){
        nextrow = row+1;
        nextcol  = 0;
    }
    if(board[row][col] != '.'){
      return helper(board,nextrow,nextcol);
    }
    for(char dig = '1';dig<='9';dig++){
        if(isSafe(board,row,col,dig)){
            board[row][col] = dig;
            if(helper(board,nextrow,nextcol)){   //agar sab sahi gya toh return true hogya    warna koi invalid nikla functioncall toh if condtion false hogya gennaraly and backtracking apply hogya phir
                return true;
            }
            board[row][col] = '.'; //backtracking
        }
    }
    return false;
}

    void solveSudoku(vector<vector<char>>& board) {
        helper(board,0,0);
    }
};