class Solution {
public:
    int countHomogenous(string s) {
    
        long n = s.size();
        long left = 0;
        long ans = 0;
        long right = 0;
        for( right = 0;right<n;right++){
          
          if(s[left]!=s[right]){
            long k = right-left;
            ans+=(k*(k+1))/2;

           while(s[left]!=s[right]) left++;
          }
        }
        long k = right-left;
        ans+=(k*(k+1))/2;
        return ans%(1000000007);
    }
};