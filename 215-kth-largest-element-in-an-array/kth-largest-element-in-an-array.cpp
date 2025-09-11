class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        multiset<int>ms;
        for(int i = 0;i<n;i++){
            ms.insert(nums[i]);
            if(ms.size()>k){
                ms.erase(ms.begin());
            }
                    
        }
        return *ms.begin();
    }
};