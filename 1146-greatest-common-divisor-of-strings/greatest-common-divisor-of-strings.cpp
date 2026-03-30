class Solution {
public:
    string gcdOfStrings(string str1, string str2) {

        // Step 1: Check compatibility
        if (str1 + str2 != str2 + str1)
            return "";

        // Step 2: Find GCD of lengths
        int n = str1.length();
        int m = str2.length();

        int gcdLen = __gcd(n, m);

        // Step 3: Return prefix
        return str1.substr(0, gcdLen);
    }
};