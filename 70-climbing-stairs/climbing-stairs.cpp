class Solution {
public:
    int climbStairs(int n) {
    
        if(n<=2)
        return n;
        int prev1 = 1;
        int prev2 = 2;
        int i = 3;
        int currSteps = 0;
        while(i<n+1){
            currSteps = prev1+prev2;
            prev1 = prev2;
            prev2 = currSteps;
            i++;
        }
        return currSteps;
    }
};