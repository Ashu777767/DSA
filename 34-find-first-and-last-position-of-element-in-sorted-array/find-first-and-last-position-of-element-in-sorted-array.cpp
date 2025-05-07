class Solution {
public:
    int binarysearchleft(vector<int>& nums,int target)
    {
        int s = 0;
        int length = nums.size();
        int e = length-1;
        int ans = -1;
        int mid = s+(e-s)/2;
        while(s<=e)
        {
            if(nums[mid] == target)
            {
                ans = mid;
                e = mid-1;
            }
            else if(nums[mid]<target){
                s = mid+1;
            }
            else{
                e = mid-1;
            }
            mid = s+(e-s)/2;
        }
        return ans;


    }
    int binarysearchright(vector<int>& nums,int target)
    {
        int s = 0;
        int length = nums.size();
        int e = length-1;
        int ans = -1;
        int mid = s+(e-s)/2;
        while(s<=e)
        {
            if(nums[mid] == target)
            {
                ans = mid;
                s = mid+1;
            }
             else if(nums[mid]<target){
                s = mid+1;
            }
            else{
                e = mid-1;
            }
            mid = s+(e-s)/2;
        }
        return ans;


    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = binarysearchleft(nums,target);
        int right = binarysearchright(nums,target);
        return {left,right};
    }
};