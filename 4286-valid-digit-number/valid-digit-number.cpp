class Solution {
public:
    bool validDigit(int n, int x) {
        bool flag = false;
        while(n>=10){
            if(n%10 == x){
              
             flag = true;
            }
            n/=10;
        }
        return n==x?false:flag;
    }
};