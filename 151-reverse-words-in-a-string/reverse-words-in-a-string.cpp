class Solution {
public:
    // Function to trim leading and trailing spaces
    string trim(string &s) {
        int start = s.find_first_not_of(' ');
        if (start == string::npos) {
            return ""; // All spaces
        }

        int end = s.find_last_not_of(' ');
        return s.substr(start, end - start + 1);
    }

    // Function to reverse a portion of the string
    void reverseword(string &s, int first, int end) {
        while (first < end) {
            swap(s[first++], s[end--]);
        }
    }

    // Function to reverse the entire string
    void stringreverse(string &s, int start, int e) {
        while (start < e) {
            swap(s[start++], s[e--]);
        }
    }

    string reverseWords(string s) {
        // Step 1: Trim leading and trailing spaces
        s = trim(s);

        // Step 2: Remove extra spaces between words
        int n = s.size();
        int i = 0, j = 0;
        while (j < n) {
            // Skip multiple spaces
            while (j < n && s[j] == ' ') {
                j++;
            }

            // If we find a non-space, copy it to the result
            if (j < n) {
                if (i != 0) s[i++] = ' '; // Only add a space if it's not the start
                while (j < n && s[j] != ' ') {
                    s[i++] = s[j++];
                }
            }
        }
        
        // Resize the string to the correct length (to remove any trailing spaces)
        s.resize(i);

        // Step 3: Reverse the entire string
        stringreverse(s, 0, s.size() - 1);

        // Step 4: Reverse each word in the string
        int first = 0;
        for (int end = 0; end <= s.size(); end++) {
            if (end == s.size() || s[end] == ' ') {
                reverseword(s, first, end - 1);
                first = end + 1;
            }
        }

        return s;
    }
};
