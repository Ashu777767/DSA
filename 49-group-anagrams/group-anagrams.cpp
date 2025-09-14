class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>anagram;
         for(string st : strs){
            string key = st;
            sort(key.begin(),key.end());  //creates the key for anagram words
            anagram[key].push_back(st);   //stores the anagrams  as values of the key which came from its sorted version
         }
         vector<vector<string>>answer;
         for(auto &it:anagram){
            answer.push_back(it.second);
         }

         return answer;
    }
};