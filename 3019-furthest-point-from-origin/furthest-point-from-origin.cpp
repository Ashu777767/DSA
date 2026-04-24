class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int left = 0;
        int right = 0;
        for (char ch : moves) {
            if (ch == 'L')
                left++;
            if (ch == 'R')
                right++;
        }
        char maxMove = left >= right ? 'L' : 'R';
        int furthest = 0;
        for (char ch : moves) {
            char check = ch == '_' ? maxMove : ch;
            if (check == 'L')
                furthest += -1;
            else
                furthest += 1;
        }
        return abs(furthest);
    }
};