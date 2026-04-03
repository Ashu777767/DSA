class Solution {
public:
    bool isSubsequence(string s, string t)  {
        int k = 0;
        for(char ch:t){
            if(ch == s[k]){
                k++;
            }
        }
        return k == s.size();
    }
};