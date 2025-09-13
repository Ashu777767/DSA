class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int n = intervals.size();
        vector<vector<int>>ans;
        for(int i = 0;i<n;i++){
            int start = intervals[i][0];
            int end = intervals[i][1];
            if(!ans.empty() && start<=ans.back()[1]){
                continue;
            }
            for(int j = i+1;j<n;j++){
                if(intervals[j][0] <=end){
                    end = (intervals[j][1]>end)?intervals[j][1]:end;

                }
                else{
                    break;
                }

            }
            ans.push_back({start,end});
        }
        return ans;
    }
};