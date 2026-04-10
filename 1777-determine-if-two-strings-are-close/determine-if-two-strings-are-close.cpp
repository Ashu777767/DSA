class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if (word1.size() != word2.size())
            return false;
        unordered_map<char, int> mp;
        unordered_map<char, int> mp1;
        for (auto ch : word2) {
            mp1[ch]++;
        }
        for (auto ch : word1) {
            mp[ch]++;
        }
        for (auto [ch, f] : mp) {
            if (mp1.find(ch) == mp1.end())
                return false;
        }
        vector<int> v1, v2;

        for (auto [ch, freq] : mp)
            v1.push_back(freq);
        for (auto [ch, freq] : mp1)
            v2.push_back(freq);

        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());

        return v1 == v2;
    }
};