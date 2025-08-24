class Solution {
public:
    int longestPalindrome(string s) {
        int count = 0;
        bool odd = false;
        unordered_map<char,int>freq;
        for(char ch : s){
            freq[ch]++;
        }
        for(auto val:freq){
            if((val.second)%2 == 0){
                count+=val.second;
            }
            else{
             count+=val.second-1;
             odd = true;
            }
        }
        if(odd)
        return count+1;
        return count;
    }
};