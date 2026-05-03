class Solution {
public:
void  findprimes( vector<bool>& isPrime,int r){
    isPrime[0] = false;
    isPrime[1] = false;
    for(int i = 2;i*i<=r;i++){
        if(isPrime[i]){
            for(int j = i*i;j<=r;j+=i){
                isPrime[j] = false;
            }
        }
    }
    return ;
}

    int sumOfPrimesInRange(int n) {
         int reverse = n;
        int r = 0;
        while(reverse>0){
            r = 10*r+(reverse%10);
            reverse/=10;
        }
        int start = min(n,r);
        int end = max(n,r);
        vector<bool>isPrime(end+1,true);
        findprimes(isPrime,end);
        long long ans = 0;
        for(int i =start;i<=end;i++){
            if(isPrime[i]) ans+=i;
            
        }
        return ans;
    }
};