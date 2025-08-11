class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int minProfit = INT_MAX;
        int maxprofit = 0;
        for(int i = 0;i<n;i++){
           minProfit = min(minProfit,prices[i]);
           maxprofit = max(maxprofit,prices[i]-minProfit);  
        }
        return maxprofit;    
    }
};