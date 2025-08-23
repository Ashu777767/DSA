class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0;
        int maxValue = 0;
        unordered_map<char,int>maps;
        for(int i = 0;i<s.size();i++){
            maps[s[i]]++;
            while(maps[s[i]]>1){
                maps[s[left]]--;
                left++;
            }
          maxValue = max(maxValue,(i-left)+1);
        }
        return maxValue;
    }
};