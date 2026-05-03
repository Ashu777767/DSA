class Solution {
public:
 bool isprime(int n){
     if(n == 0 || n == 1){
         return false;
     }
     if(n==2) return true;
        for(int i = 2;i<=n/2;i++){
            if(n%i == 0){
                return false;
            }
        }
     return true;
    }
    
    int sumOfPrimesInRange(int n) {
         int reverse = n;
        int r = 0;
        while(reverse>0){
            r = 10*r+(reverse%10);
            reverse/=10;
        }
        long long ans = 0;
        int start = min(n,r);
        int end = max(n,r);
        for(int i = start;i<=end;i++){
            if(isprime(i)){
                ans+=i;
            }
        }
        return ans;
    }
};