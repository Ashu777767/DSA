class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        vector<int>p(n,0);
        int left = 0;
        p[0] = nums[0];
        for(int i = 1;i<n;i++){
            p[i] = p[i-1]+nums[i];
        }
        for(int i =0;i<n;i++){
            int right = p[n-1]-p[i];
            if(right == left){
                return i;
            }
            left = p[i];
        }
        return -1;
    }
};