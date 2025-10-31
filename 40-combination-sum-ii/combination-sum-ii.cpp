class Solution {
public:
    void getAllcombinations(vector<int>& arr, int target, int idx, vector<vector<int>>& ans, vector<int>& combi) {
        if (target == 0) {
            ans.push_back(combi);
            return;
        }
        if (target < 0 || idx == arr.size())
            return;

        // Include current element
        combi.push_back(arr[idx]);
        getAllcombinations(arr, target - arr[idx], idx + 1, ans, combi);
        combi.pop_back();

        // Skip duplicates at the same level
        while (idx + 1 < arr.size() && arr[idx] == arr[idx + 1]) idx++;

        // Exclude current element
        getAllcombinations(arr, target, idx + 1, ans, combi);
    }

    vector<vector<int>> combinationSum2(vector<int>& arr, int target) {
        sort(arr.begin(), arr.end());
        vector<vector<int>> ans;
        vector<int> combi;
        getAllcombinations(arr, target, 0, ans, combi);
        return ans;
    }
};
