class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int len1 = s1.length();
    int len2 = s2.length();
    
    if (len1 > len2) return false;

    vector<int> s1Freq(26, 0);
    vector<int> s2Freq(26, 0);

    // Populate frequency arrays for s1 and the first window of s2
    for (int i = 0; i < len1; i++) {
        s1Freq[s1[i] - 'a']++;
        s2Freq[s2[i] - 'a']++;
    }

    // Check the first window
    if (s1Freq == s2Freq) return true;

    // Slide the window over s2
    for (int i = len1; i < len2; i++) {
        // Include the next character in the window
        s2Freq[s2[i] - 'a']++;
        // Exclude the character going out of the window
        s2Freq[s2[i - len1] - 'a']--;

        // Compare the frequency arrays
        if (s1Freq == s2Freq) return true;
    }

    return false;
    }
};