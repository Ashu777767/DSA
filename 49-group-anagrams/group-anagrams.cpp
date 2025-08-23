class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
         unordered_map<string, vector<string>> mp;

        for (string s : strs) {
            vector<int> count(26, 0);
            for (char c : s) count[c - 'a']++;

            string key;
            for (int num : count) {
                key += "#" + to_string(num); // build unique signature
            }
            mp[key].push_back(s);
        }

        vector<vector<string>> result;
        for (auto &p : mp) result.push_back(p.second);
        return result;
    }
};