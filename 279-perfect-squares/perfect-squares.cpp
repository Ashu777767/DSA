class Solution {
public:
    int numSquares(int n) {
        vector<int>dp(n+1,INT_MAX);
        dp[0] = 0;
        for(int i = 1;i<=n;i++){
            for(int j = 1;j*j<=i;j++){ //gives valid square under n
               int sq = j*j;
               dp[i] = min(dp[i],dp[i-sq]+1); // i-sq defines let sq be the last sqaure of required n
                                              // for 13 = last is 4 + remaining will be(13-4) = dp[9]
                                              // +1 is for the last value count that we conisdered
            }
        }
        return dp[n];
    }
};