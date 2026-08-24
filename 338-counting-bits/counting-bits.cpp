class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>ans(n+1,0);
        for(int i = 0;i<=n;i++){
            int bits = i;
            int count = 0;
          while(bits>0){
            bits = bits&(bits-1);
            count++;
          }
          ans[i] = count;
        }
        return ans;
    }
};