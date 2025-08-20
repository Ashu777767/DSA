class Solution {
public:
    bool isPalindrome(string s) {
        string cleanStr = "";
        for(char ch : s){
            if(isalnum(ch))
           cleanStr+=tolower(ch);
        }
        string revStr = cleanStr;
        reverse(revStr.begin(),revStr.end());


        return cleanStr.compare(revStr) == 0;
    }
};