class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int mp[26] = { 0 };
        for(char ch:magazine){
            mp[ch-'a']++;
        }
        for(char ch:ransomNote){
            if(--mp[ch-'a']<0){
                return false;
            }
        }
        return true;
    }
};