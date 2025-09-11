class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<int,vector<int>,greater<int>>pq;  //minheap sotes as 1->2->3 front at 1 pop at 1 top at 1 only push at back
        for(int i = 0;i<n;i++){
            pq.push(nums[i]);
            if(pq.size()>k){
                pq.pop();
            }
                    
        }
        return pq.top() ;
    }
};