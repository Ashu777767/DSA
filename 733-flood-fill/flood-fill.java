class Solution {
   public static  void floodthebox(int sr, int sc, int[][] image, int color,
                     int rows, int col, int original) {
        if (sr < 0 || sc < 0 || sr > rows || sc > col ||
            image[sr][sc] != original) {
            return;
        }
        // vis[sr][sc] = true; not required beacuse everytime we visit a correct
        // node we mark it to color so why wee need vis the image[sr][sc] itself
        // handels it no need
        image[sr][sc] = color;
        floodthebox(sr - 1, sc, image, color, rows, col, original); // up
        floodthebox(sr + 1, sc, image, color, rows, col, original); // down
        floodthebox(sr, sc - 1, image, color, rows, col, original); // left
        floodthebox(sr, sc + 1, image, color, rows, col, original); // right
        return;
    }

    public int[][] floodFill(int[][] image, int sr, int sc, int color) {
         if (image[sr][sc] == color)
            return image; // if vis removed this edge case came what if
                          // everthing is 0 then it may cause overflow so add
                          // this edgecase check condition
        int original = image[sr][sc];
        int rows = image.length - 1;
        int col = image[0].length - 1;

        floodthebox(sr, sc, image, color, rows, col, original);
        return image;
    }
}