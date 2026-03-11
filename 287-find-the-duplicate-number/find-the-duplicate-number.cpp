class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        int slow = 0,fast = 0;
        slow = nums[slow];
        fast = nums[nums[fast]];
        while(slow!=fast){        //agar notie karega to saare values 1 to n ki range mai honge which means har value ek index bhi hosakta hai which means likedlist ki tarah point kar raha hai har value jisss hame idea haya for floyod alogorithm
        slow = nums[slow];
        fast = nums[nums[fast]];
        }
        slow = 0;
        while(slow != fast){
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};