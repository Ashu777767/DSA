class Solution {
    public int arraySign(int[] nums) {
        int neg_count = 0;
        for(int val:nums){
            if(val == 0) return 0;
            if(val<0){
                neg_count++;
            }
        }
        return neg_count%2 == 0?1:-1;
    }
}