class Solution {
public:
    bool isVowel(char ch) {
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
    }
    int maxVowels(string s, int k) {
        int n = s.size();
        int left = 0;
        int count = 0;
        int maximum = 0;
        for (int i = 0; i < n; i++) {
            count = isVowel(s[i]) ? count + 1 : count;
            if ((i - left + 1) == k) {
                maximum = max(count, maximum);
                if (isVowel(s[left]))
                    count--;
                left++;
            }
        }
        return maximum;
    }
};