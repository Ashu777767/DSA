class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        int left = 0;
        int sum = 0;
        double maximum = numeric_limits<double>::lowest();
        for(int right = 0;right<n;right++){
            int len = right-left+1;
            sum+=nums[right];
            while((right-left+1) >= k){
                double avg = (double) sum/k;
               maximum = avg>maximum?avg:maximum;
               sum-=nums[left++];
            }

        }
        return maximum;
    }
};