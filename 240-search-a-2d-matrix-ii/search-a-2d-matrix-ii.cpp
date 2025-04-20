class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int r = matrix.size();
    int c = matrix[0].size();
    for(int i = 0;i<r;i++){
        if(matrix[i][0] <= target && matrix[i][c-1]>=target){
            int s  = 0;
            int e = c-1;
            while(s<=e){
                int mid = s+(e-s)/2;
                int element = matrix[i][mid];
                if(element == target){
                    return true;
                }else if(element>target){
                    e = mid-1;
                }else{
                    s = mid+1;
                }
            }
        }
    }
    return false;
    }
};