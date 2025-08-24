class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>anagram;
        for(string s :strs){
            string key = s;
            sort(key.begin(),key.end());
            anagram[key].push_back(s);
        }
        vector<vector<string>> answer;
        for(auto val:anagram){
            answer.push_back(val.second);
        }
        return answer;
    }
};