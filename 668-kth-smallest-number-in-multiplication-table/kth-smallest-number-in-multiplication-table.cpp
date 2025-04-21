class Solution {
public:
    int findKthNumber(int m, int n, int k) {
        int s = 1;
        int e = m*n;
        int ans = -1;
        while(s<=e){
            int mid = s+(e-s)/2;
            if(islessthank(m,mid,n,k)>=k){
                ans = mid;
                e = mid-1;
            }else{
                s = mid+1;
            }
        }
        return ans;
    }
    int islessthank(int m,int mid,int n,int k){
        int count = 0;
        for(int i = 1;i<=m;i++){
            count+= min(mid/i,n);
        }
        return count;
    }
};