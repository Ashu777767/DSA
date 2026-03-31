class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int n = candies.size();
        vector<bool>ans(n,false);
        int max = 0;
        for(int candie:candies){
            max = candie>max?candie:max;
        }
        for(int i =0;i<n;i++){
            if(candies[i]+extraCandies>=max){
                ans[i] = true;
            }
        }
        return ans;
    }
};