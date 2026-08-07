class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
    string word;
    vector<string> words;

    // Step 1: Extract words, automatically skipping extra spaces
    while (ss >> word) {
        words.push_back(word);
    }

    // Step 2: Reverse the list of words
    reverse(words.begin(), words.end());

    // Step 3: Join the words into a single string
    string ans = "";
    for (int i = 0; i < words.size(); i++) {
        if (i > 0)  ans+=" ";  // Add space between words
        ans+=words[i];
    }

    return ans;

    }
};