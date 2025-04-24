class Solution {
public:
    bool isminimumsum(vector<int>& nums, int k,int n,int mid){
        int kcount = 1;
        int sum = 0;
        for(int i = 0;i<n;i++){
            if(nums[i]+sum <= mid){
                sum+=nums[i];
            }else{
                if(kcount<k){
                    kcount++;
                    sum = nums[i];
                }
                else{
                    return false;
                }
            }
        }
        return true;
    }
    int splitArray(vector<int>& nums, int k) {
        int s =  *max_element(nums.begin(), nums.end());
        int n = nums.size();
        int ans = -1;
        int max = 0;
        for(int i = 0;i<n;i++){
             max+=nums[i];
        }
        int e = max;
        int mid = s+(e-s)/2;
        while(s<=e){
            if(isminimumsum(nums,k,n,mid)){
                ans = mid;
                e = mid-1;
            }else{
                s = mid+1;
            }
            mid = s+(e-s)/2;
        }
        return ans;
    }
};