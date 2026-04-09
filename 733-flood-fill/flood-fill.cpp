class Solution {
public:
 void floodthebox(int sr, int sc,vector<vector<int>>& image, vector<vector<bool>>& vis,int color,int rows,int col,int original){
    if(sr<0 || sc<0 || sr>rows || sc>col || vis[sr][sc] || image[sr][sc] != original){
        return ;
    }
    vis[sr][sc] = true;
    image[sr][sc] = color;
    floodthebox(sr-1,sc,image,vis,color,rows,col,original);  //up  
    floodthebox(sr+1,sc,image,vis,color,rows,col,original);    //down
    floodthebox(sr,sc-1,image,vis,color,rows,col,original);    //left
    floodthebox(sr,sc+1,image,vis,color,rows,col,original);    //right
    return ;
 }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int original =  image[sr][sc];
        int rows = image.size();
        int col = image[0].size();
        vector<vector<bool>> vis(rows, vector<bool>(col, false));
      floodthebox(sr,sc,image,vis,color,rows-1,col-1,original); 
      return image;
    }
};