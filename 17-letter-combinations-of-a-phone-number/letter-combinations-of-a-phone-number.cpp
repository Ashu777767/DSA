class Solution {
public:
  void findNumber(unordered_map<char,string>dail,vector<string>& combination,string substring,int index,int digitsize,string digits){
    if(index == digitsize){
        combination.push_back(substring);
        return ;
    }
    for(int i = 0;i<dail[digits[index]].size();i++){
        string word = dail[digits[index]];
        substring+=word[i];
         findNumber(dail,combination,substring,index+1,digitsize,digits);
         substring.pop_back();
    }
  }

    vector<string> letterCombinations(string digits) {
        unordered_map<char,string>dail = {{'2',"abc"},{'3',"def"},{'4',"ghi"},{'5',"jkl"},{'6',"mno"},{'7',"pqrs"},{'8',"tuv"},{'9',"wxyz"}};
       vector<string>combination;
       string substring = "";
       int digitsize = digits.size();
        findNumber(dail,combination,substring,0,digitsize,digits);
        return combination;

    
    }
};