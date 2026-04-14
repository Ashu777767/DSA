class Solution {
public:
    string decodeString(string s) {
        stack<int> numStack;
        stack<string> strStack;

        string current = "";
        int num = 0;

        for (char ch : s) {
            if (isdigit(ch)) {
                num = num * 10 + (ch - '0'); // handle multi-digit
            } else if (ch == '[') {
                numStack.push(num);
                strStack.push(current);
                num = 0;
                current = "";
            } else if (ch == ']') {
                string temp = current;
                int count = numStack.top();
                numStack.pop();

                current = strStack.top();
                strStack.pop();

                for (int i = 0; i < count; i++) {
                    current += temp;
                }
            } else {
                current += ch;
            }
        }

        return current;
    }
};