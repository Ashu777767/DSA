class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int altitude = 0;
        int highest = 0; 
        
        for(int val : gain){
            altitude += val;                
            highest = max(highest, altitude); 
        }
        
        return highest;
    }
};