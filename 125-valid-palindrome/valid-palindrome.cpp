class Solution {
public:
    bool isPalindrome(string s) {
        int right = s.length()-1;
        int i = 0;
        while(i<=right)
        {
            if(isalnum(s[i]) && isalnum(s[right])){
                if(tolower(s[i]) == tolower(s[right])){
                    right--;
                    i++;
                }
                else{
                    return false;
                }
            }
            else if(!(isalnum(s[right]))){
                right--;
            }
            else{
                i++;
            }
        }
        return true;
    }
};