class Solution {
public:
    vector<string> letterCombinations(string digits) {

        if (digits.empty())
            return {};

        unordered_map<char, string> dial = {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
        };

        queue<string> q;
        q.push("");

        for (char digit : digits) {

            string letters = dial[digit];

            int size = q.size();

            while (size--) {

                string current = q.front();
                q.pop();

                for (char ch : letters) {
                    q.push(current + ch);
                }
            }
        }

        vector<string> result;

        while (!q.empty()) {
            result.push_back(q.front());
            q.pop();
        }

        return result;
    }
};