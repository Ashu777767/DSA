class Solution {
public:
bool targetfound(vector<int>& nums,int target,int &ans){
    int s = 0;
    int length = nums.size();
    int e = length-1;
    int mid = s+(e-s)/2;
    while(s<=e){
        if(nums[mid] == target){
            ans = mid;
            return true;
        }
        else if(nums[mid]<target)
        {
            s = mid+1;
        }else{
            e = mid-1;
        }
        mid = s+(e-s)/2;
    }
    return false;
}
 int checkinsertion(vector<int>& nums,int target){
    int s = 0;
    int length = nums.size();
    int e = length-1;
    int mid = s+(e-s)/2;
    while(s<=e){
         if(nums[mid]<target)
        {
            s = mid+1;
        }else{
            e = mid-1;
        }
        mid = s+(e-s)/2;
    }
    return mid;
 }
    int searchInsert(vector<int>& nums, int target) {
        int ans = -1;
        if (targetfound(nums,target,ans)){
            return ans ;

        }
        else{
            int  pos = checkinsertion(nums,target);
            return pos;
        }
    }
};