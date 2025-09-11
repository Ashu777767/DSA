class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int>map;
        for(char ch:s) map[ch]++;  //0(n)

        for(int i = 0;i<s.size();i++){  //0(n)
            if(map[s[i]] == 1){
                return i;
            }
        }
        return -1;
    }
};