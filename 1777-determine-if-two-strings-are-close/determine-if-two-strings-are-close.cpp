class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.size() != word2.size()) return false;

        vector<int> freq1(26, 0), freq2(26, 0);

        for(char ch : word1) freq1[ch - 'a']++;
        for(char ch : word2) freq2[ch - 'a']++;

        // ✅ Condition 1: same characters
        for(int i = 0; i < 26; i++){
            if((freq1[i] == 0 && freq2[i] != 0) ||
               (freq1[i] != 0 && freq2[i] == 0))
                return false;
        }

        // ✅ Count frequency of frequencies
        unordered_map<int,int> count1, count2;

        for(int f : freq1){
            if(f > 0) count1[f]++;
        }

        for(int f : freq2){
            if(f > 0) count2[f]++;
        }

        return count1 == count2;
    }
};