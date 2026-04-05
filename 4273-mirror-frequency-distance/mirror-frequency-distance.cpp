

class Solution {
public:
    int mirrorFrequency(string s) {
        unordered_map<char,int> mp;

        // count frequency
        for(char ch : s){
            mp[ch]++;
        }

        int ans = 0;

        // alphabets
        for(char ch = 'a'; ch <= 'z'; ch++){
            char mirror = 'a' + ('z' - ch);

            if(ch > mirror) continue;   // avoid double counting

            ans += abs(mp[ch] - mp[mirror]);
        }

        // digits
        for(char ch = '0'; ch <= '9'; ch++){
            char mirror = '0' + ('9' - ch);

            if(ch > mirror) continue;

            ans += abs(mp[ch] - mp[mirror]);
        }

        return ans;
    }
};