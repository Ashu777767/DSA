class Solution {
public:
    int longestPalindrome(string s) {
         unordered_map<char,int> freq;
        for(char c : s) freq[c]++;

        int ans = 0;
        for(auto &p : freq) ans += (p.second / 2) * 2;  // add even part
        
        // if any odd exists, put one in center
        if(ans < s.size()) ans += 1;  

        return ans;
    }
};