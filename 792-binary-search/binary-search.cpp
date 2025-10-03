class Solution {
public:
int checkTarget(vector<int>arr,int s,int e,int target){
    if(s<=e){
    int mid = s+(e-s)/2;
    if(arr[mid] == target)
    {
        return mid;
    }
    else if(arr[mid]<=target){
        return checkTarget(arr,mid+1,e,target);
    }
    else{
        return checkTarget(arr,s,mid-1,target);
    }
    }
    return -1;
}
    int search(vector<int>& arr, int target) {
        int s = 0;
        int e = arr.size()-1;
        return checkTarget(arr,s,e,target);
    }
};