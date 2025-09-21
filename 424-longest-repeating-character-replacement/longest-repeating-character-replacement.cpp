class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int>freq(26,0);
        int n = s.size();
        int l = 0;
        int maxfreq = 0;
        int ans  = 0;
        for(int r = 0;r<n;r++){
           freq[s[r]-'A']++;
           maxfreq = max(maxfreq,freq[s[r]-'A']);
           if(((r-l+1)-maxfreq) > k)
           {
            freq[s[l]-'A']--;
            l++;
           }
           ans = max((r-l+1),ans);
        }
        return ans;
    }
};