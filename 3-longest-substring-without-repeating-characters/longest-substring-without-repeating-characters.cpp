class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length()<=0){
            return 0;
        }
        int left = 0;
        int len;
        int maxiMuM = INT_MIN;
        unordered_set<char>check;
        for(int right = 0;right<s.length();right++)
        {
           while(check.count(s[right])){
                  check.erase(s[left]);
                  left++;
           }
           check.insert(s[right]);
           maxiMuM = max(maxiMuM,right-left+1);

        }
        return maxiMuM;
    }
};