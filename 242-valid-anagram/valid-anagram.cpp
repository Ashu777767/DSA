class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int>str1;
        unordered_map<char,int>str2;
        for(char ch:s){
            str1[ch]++;
        }
        for(char ch:t){
            str2[ch]++;
        }

       return str1 == str2;
    }
    
};