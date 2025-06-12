class Solution {
public:
    bool isPalindrome(int x) {
        long val = 0;
        int original = x;
        while(x>0)
        {
          int digit = x%10;
         val = val*10+digit ;
         x/=10;
         }
         if(val == original)
         return true;
     return false;
    }
    
};