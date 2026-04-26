class Solution {
public:
    bool isVowel(char c) {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            return true;
        }
        return false;
    }
    string sortVowels(string s) {
        unordered_map<char, int> freq;
        unordered_map<char, int> firstIndex;

        for (int i = 0; i < s.size(); i++) {
            if (isVowel(s[i])) {
                freq[s[i]]++;
                if (!firstIndex.count(s[i])) {
                    firstIndex[s[i]] = i;
                }
            }
        }

        vector<pair<char, int>> vec(freq.begin(), freq.end());

        sort(vec.begin(), vec.end(), [&](auto& a, auto& b) {
            if (a.second == b.second)
                return firstIndex[a.first] < firstIndex[b.first];
            return a.second > b.second;
        });

        string vowel = "";
        for (auto it : vec) {
            vowel += string(it.second, it.first);
        }

        int k = 0;
        for (int i = 0; i < s.size(); i++) {
            if (isVowel(s[i])) {
                s[i] = vowel[k++];
            }
        }

        return s;
    }
};