class Solution {
public:
bool isPalin(string part){
    string s2 = part;
    reverse(s2.begin(),s2.end());
    return s2 == part;
}
   void getAllpalindrome(string s,vector<vector<string>> &ans, vector<string>& partion)
   {
     if(s.size() == 0)
     {
        ans.push_back(partion);
        return;
     }
     for(int i = 0;i<s.size();i++){
        string part = s.substr(0,i+1);  //total length of substring from 0
        if(isPalin(part)){
            partion.push_back(part);
            getAllpalindrome(s.substr(i+1),ans,partion);
            partion.pop_back(); //while backtracking
        }
     }
   }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>partion;
        getAllpalindrome(s,ans,partion);
        return ans;
    }
};