class Solution {
public:
bool isminimum(vector<int>& weights,int n,int days,int mid){
    int kilo = 0;
    int time = 1;
    for(int i = 0;i<n;i++){
        if(kilo+weights[i]<=mid){
            kilo+=weights[i];
        }
        else{
            kilo = weights[i];
            time++;
        }
    }
    return time<=days;
}
    int shipWithinDays(vector<int>& weights, int days) {
        int s = *max_element(weights.begin(),weights.end());
        int e = accumulate(weights.begin(),weights.end(),0);
        int n = weights.size();
        int ans = -1;
        int mid = s+(e-s)/2;
        while(s<=e){
            if(isminimum(weights,n,days,mid)){
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