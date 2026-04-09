class Solution {
    public int largestAltitude(int[] gain) {
         int altitude = 0;
        int highest = 0; 
        
        for(int val : gain){
            altitude += val;                
            highest = Math.max(highest, altitude); 
        }
        
        return highest;
    }
}