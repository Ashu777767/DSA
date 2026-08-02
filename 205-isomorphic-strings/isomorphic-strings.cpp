class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char>mp;
        set<char>st;
        int i = 0;
        for(char ch:s){
            if(mp.count(ch) && mp[ch]!=t[i]){
              return false;
            }else if(st.count(t[i]) == 0){
                mp[ch] = t[i];
                st.insert(t[i]);
            }
            i++;
        }
       for(char ch:s){
        if(!mp.count(ch)) return false;
       }
       return true;
    }
};