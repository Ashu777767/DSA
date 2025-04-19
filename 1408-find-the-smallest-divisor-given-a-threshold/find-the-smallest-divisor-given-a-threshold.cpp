class Solution {
public:
bool issumtrue(vector<int>& nums, int threshold,int mid,int n){
    int sum = 0;
    for(int i = 0;i<n;i++){
        sum += (nums[i]+ (mid-1))/mid;
    }
    return sum <= threshold;
}
    int smallestDivisor(vector<int>& nums, int threshold) {
        int s = 1;
        int end = *max_element(nums.begin(),nums.end());
        int n = nums.size();
        int ans = -1;
        int mid = s+(end-s)/2;
        while(s<=end){
            if( issumtrue(nums,threshold,mid,n)){
                ans = mid;
                end = mid-1;
            }
            else{
                s = mid+1;
            }
            mid = s+(end-s)/2;
        } 
        return ans;
    }
};