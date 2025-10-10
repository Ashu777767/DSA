class Solution {
public:
bool isSafe(int row,int n,vector<string> &board,int col)
 {
    for(int i = 0;i<n;i++){ //check the particular row
         if(board[row][i] == 'Q'){
            return false;
         }
    }
    for(int i = 0;i<n;i++)
    {
        if(board[i][col] == 'Q'){   //checking the particular column
            return false;
        }
    }
   for(int i = row,j = col;i>=0 && j>=0;i--,j--){  //checking the left upward diagnol for the position
    if(board[i][j] == 'Q')
    {
        return false;
    }

   }
     for(int i = row,j = col;i>=0 && j>=0;i--,j++){  //checking the right upward diagnol for the position
    if(board[i][j] == 'Q')
    {
        return false;
    }
   }
   return true;
 }

void placeNqueens( vector<string>& board,vector<vector<string>>& ans,int n,int row,int &count)
   {
     if(row>=n){
        ans.push_back({board});
        count++;
        return ;
     }
    for(int col = 0;col<n;col++){
        if(isSafe(row,n,board,col)){
            board[row][col] = 'Q';    //do 
            placeNqueens(board,ans,n,row+1,count);
            board[row][col] = '.';   //undo step for invalid position check during backtracking
        }
    
    }

   }
    int totalNQueens(int n) {
        vector<string>board(n,string(n,'.'));
        vector<vector<string>>ans;
        int row = 0;
        int count = 0;
        placeNqueens(board,ans,n,row,count);
        return count;
    }
};