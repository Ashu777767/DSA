class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
          if (intervals.empty()) return 0;
        
        // Step 1: Sort by end time
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b) {
            return a[1] < b[1];
        });
        
        int countKeep = 1; // at least one interval kept
        int lastEnd = intervals[0][1];
        
        // Step 2: Iterate over intervals
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] >= lastEnd) {
                // Non-overlapping → keep it
                countKeep++;
                lastEnd = intervals[i][1];
            }
        }
        
        // Step 3: Min removals = total - kept
        return intervals.size() - countKeep;
    
    }
};