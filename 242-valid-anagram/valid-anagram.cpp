class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!= t.size()){    //edge case
        return false;             
        }
        unordered_map<char,int>str1;
        for(char ch:s){
            str1[ch]++;
        }
        for(char ch:t){
            if(--str1[ch]<0)
            return false;
        }

       return true;
    }
    
};