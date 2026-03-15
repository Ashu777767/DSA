class Solution {
public:
    bool isUgly(int n) {
        vector<int>arr = {2,3,5};
        if(n==0) return false;
        for(int val:arr){
            while(n%val == 0){
                n/=val;
            }
          
        }
        return n==1;
    }
};