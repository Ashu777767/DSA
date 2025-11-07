class Solution {
public:
bool checkwinner(vector<vector<char>>grid,int r,int c,char letter){
    //row check
    if(grid[r][0] == letter && grid[r][1] == letter && grid[r][2] == letter)
    {
        return true;
    }
    // check col
        if (grid[0][c] == letter && grid[1][c] == letter && grid[2][c] == letter)
            return true;

        // main diagonal
        if (r == c && grid[0][0] == letter && grid[1][1] == letter && grid[2][2] == letter)
            return true;

        // anti diagonal
        if (r + c == 2 && grid[0][2] == letter && grid[1][1] == letter && grid[2][0] == letter)
            return true;

            return false;
}
    string tictactoe(vector<vector<int>>& moves) {
        vector<vector<char>>grid(3,vector<char>(3,'.'));
        char letter  = 'X';
        for(int i = 0;i<moves.size();i++){
            int r = moves[i][0];
            int c = moves[i][1];
            grid[r][c] = letter;

            if(checkwinner(grid,r,c,letter)){
                return (letter == 'X')?"A":"B";
            }
            letter = (letter == 'X')?'0':'X';

        }
        if(moves.size() == 9) return "Draw";
        
        return "Pending";
    }
};