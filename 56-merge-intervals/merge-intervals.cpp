class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
     int n = intervals.size();
     sort(intervals.begin(),intervals.end());
     vector<vector<int>>ans;
     for(int i = 0;i<n;i++){
        int start = intervals[i][0];
        int end = intervals[i][1];
        if(ans.empty() || (ans.back()[1]<start)){
            ans.push_back({start,end});
        }
        else if(ans.back()[1]>=start){
            //  if(start<ans.back()[0])
            // ans.back()[0] = min(ans.back()[0],start);
            ans.back()[1] = max(ans.back()[1],end);
        }
     }
     return ans;
    }
};