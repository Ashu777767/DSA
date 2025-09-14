class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // if(s.size() == 0){
        //     return 0;
        // } edge case
        int maxLen = 0;  //for edge case 
        int n = s.size();    //substring longest so sliding window
        int left = 0;
        unordered_map<char,int>map;
        for(int r = 0;r<n;r++){   //0(n)
            
            //if duplicate found
            while(map[s[r]]>0){
                map[s[left]]--;
                left++;
            }
            map[s[r]]++;
            maxLen = max(maxLen,(r-left+1));
        }

        return maxLen;
    }
};