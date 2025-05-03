class Solution {
public:
char tolowercase(char ch) {
    if (ch >= 'a' && ch <= 'z') {
        return ch;
    } else if (ch >= 'A' && ch <= 'Z') {
        return ch - 'A' + 'a';
    }
    return ch;
}
    bool isPalindrome(string s) {
        
    int st = 0;
    int e = s.size() - 1;

    while (st <= e) {
        // Skip non-alphanumeric characters from the start
        if (!((s[st] >= 'a' && s[st] <= 'z') || 
              (s[st] >= 'A' && s[st] <= 'Z') || 
              (s[st] >= '0' && s[st] <= '9'))) {
            st++;
        }
        // Skip non-alphanumeric characters from the end
        else if (!((s[e] >= 'a' && s[e] <= 'z') || 
                   (s[e] >= 'A' && s[e] <= 'Z') || 
                   (s[e] >= '0' && s[e] <= '9'))) {
            e--;
        }
        // Compare characters
        else {
            if (tolowercase(s[st]) != tolowercase(s[e])) {
                return false;
            }
            st++;
            e--;
        }
    }
    return true;
}
};