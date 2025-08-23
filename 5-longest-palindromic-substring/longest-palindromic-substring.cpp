class Solution {
public:

    string longestPalindrome(string s) {
        int n = s.size();
        int start = 0;
        int maxLen = 1;
        for(int i = 0;i<s.size();i++)
        {
           int left = i;
           int right = i;
        //    
        while(left >= 0 && right < n && s[left] == s[right]) {
    if ((right - left + 1) > maxLen) {
        start = left;
        maxLen = (right - left + 1);
    }
    left--;
    right++;
}

         left = i;
         right = i+1;
        
        while(left >= 0 && right < n && s[left] == s[right]) {
    if ((right - left + 1) > maxLen) {
        start = left;
        maxLen = (right - left + 1);
    }
    left--;
    right++;
}

        }
        
        return s.substr(start,maxLen);
    }
};