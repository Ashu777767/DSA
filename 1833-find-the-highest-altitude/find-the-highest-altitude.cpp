class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int altitude = 0;
        int highest = INT_MIN;
        for(int val:gain){
            highest = altitude>highest?altitude:highest;
            altitude+=val;
        }
         highest = altitude>highest?altitude:highest;
        return highest;
    }
};