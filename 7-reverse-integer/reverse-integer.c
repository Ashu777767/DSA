int reverse(int x){
     int ans = 0;
     while(x!=0){
       long long int digit = x%10;
       if(ans>INT_MAX/10 || ans<INT_MIN/10)
        return 0;
        ans = (ans*10)+digit;
        x/=10;
     }
     ans = x<0?-ans:ans;
     return ans;
}