class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string  ans = "";
        for(int i = 0;i<strs[0].size();i++){
            char ch = strs[0][i];
            int j = 1;
            while(j<strs.size())
            {
                if(ch == strs[j][i]){
                    j++;
                }
                else{
                    return ans;
                }
            }
            if(j>=strs.size()){
                ans+=ch;
            }
        }
        return ans;

    }
};