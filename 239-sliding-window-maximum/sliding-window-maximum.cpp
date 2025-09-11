class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int>result;
        deque<int>dq;
        //deque 0(n)
        //1st window
        for(int i = 0;i<k;i++)   //0(k)
        {
            while(dq.size()>0 && nums[dq.back()] <= nums[i]){
                dq.pop_back();
            }
            dq.push_back(i);  
            //storinf indexes as we will check it contains element of current window using i-k so we store index insterad of element
        }
     //from 2nd window
     for(int i = k;i<nums.size();i++){ //0(n-k) so => 0(n)
        result.push_back(nums[dq.front()]);
        //case 1 checks deque contains elements only of curr window
        while(dq.size()>0 && dq.front()<= (i-k)){
              dq.pop_front();
        } 
        //case 2: same as window 1 check vilabe if nums[i] greater then pop else push
         while(dq.size()>0 && nums[dq.back()] <= nums[i]){
                dq.pop_back();
            }
            dq.push_back(i); 
     } 
        result.push_back(nums[dq.front()]);  //lat value may not get included as loop ends so include it


     return result;
    }
};