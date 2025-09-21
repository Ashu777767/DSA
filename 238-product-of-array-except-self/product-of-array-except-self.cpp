class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans(n);
        ans[0] = 1;
        for(int i = 1;i<n;i++){
            ans[i] = ans[i-1]*nums[i-1];  //har index pai uske phele index tak ki left multiple store hoti hai [1,1,2,6];
        }
        int right = 1;
        for(int i = n-1;i>=0;i--){
            ans[i]*= right;
            right*=nums[i];  //abb har index pai ans mai left product upto its previous hai and usko ham abb right se multiply karte hai right ke values ke sath of particular index which provides the answer of product for each index;
        }
        return ans;
    }
};