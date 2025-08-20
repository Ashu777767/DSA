class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(),strs.end());
        string st = strs[0];
        string end = strs[strs.size()-1];
        string ans = "";
        int  i = 0;
        while(i<st.size())
        {
            if(st[i] == end[i]){
               ans+=st[i];
               i++;
            }
            else{
                break;
            }
        }
        return ans;

    }
};