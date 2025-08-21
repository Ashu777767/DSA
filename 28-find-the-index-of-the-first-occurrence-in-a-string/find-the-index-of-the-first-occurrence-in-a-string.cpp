class Solution {
public:
    int strStr(string haystack, string needle) {
        int firstStr = 0;
        int secondStr = 0;
        while(firstStr<haystack.size() && secondStr<needle.size()){
            if(haystack[firstStr+secondStr] == needle[secondStr]){
                secondStr++;
            }
            else{
                 secondStr = 0;
                firstStr++;
            }
        }
        if(secondStr>=needle.size()){
            return firstStr;
        }
        return -1;
    }
};