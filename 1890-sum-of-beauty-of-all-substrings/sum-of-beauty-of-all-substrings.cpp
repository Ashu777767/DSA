class Solution {
public:
    int beautySum(string s) {
        int n = s.size();
        int sum = 0;
         for(int i = 0;i<n;i++){
            vector<int>freq(26,0);
            for(int j = i;j<n;j++){
              int idx = s[j]-'a';
              freq[idx]++;
             int maxi = *max_element(freq.begin(), freq.end());
             int mini = INT_MAX;
             for(int val:freq){
                if(val>0){
                    mini = min(mini,val);
                }
             }
             sum+=(maxi-mini);
            }
         }
         return sum;
    }
};