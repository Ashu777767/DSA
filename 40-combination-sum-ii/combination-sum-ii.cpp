class Solution {
public:
    void backtrack(vector<int>& arr, int target, int idx, vector<int>& combi, vector<vector<int>>& ans) {
        if(target == 0) {
            ans.push_back(combi);
            return;
        }
        if(target < 0 || idx == arr.size()) return;

        for(int i = idx; i < arr.size(); i++) {
            // skip duplicates at the same recursive level
            if(i > idx && arr[i] == arr[i-1]) continue;

            combi.push_back(arr[i]);
            backtrack(arr, target - arr[i], i + 1, combi, ans); // move to next index (use each element once)
            combi.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> combi;
        backtrack(candidates, target, 0, combi, ans);
        return ans;
    }
};
