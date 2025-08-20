class Solution {
public:
void helper(vector<char>& s, int left, int right) {
        // base case: when pointers cross
        if (left >= right) return;

        // swap current characters
        swap(s[left], s[right]);

        // recursive call for inner substring
        helper(s, left + 1, right - 1);
    }
    void reverseString(vector<char>& s) {
         helper(s, 0, s.size() - 1);
    }
};