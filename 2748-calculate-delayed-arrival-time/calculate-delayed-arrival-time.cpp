class Solution {
public:
    int findDelayedArrivalTime(int arrivalTime, int delayedTime) {
        int arrival = arrivalTime+delayedTime;
        return arrival%24;
    }
};