class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int maximum = INT_MIN; 
        int currSum = 0;   //tle margaya
       for(int i = 0;i<n;i++){
          currSum+=nums[i];
          maximum = max(currSum,maximum);
          if(currSum<0){   //kyu ki agar negative hai toh aage jake subbarray sum ko chota karega isliye its better to make it as zero according to kadane's algo is tharah O(n) hogayega
             currSum = 0;
          }
       }
       return maximum;

    }
};