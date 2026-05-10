class Solution {
public:
    vector<int> scoreValidator(vector<string>& events) {
        int score = 0;
        int counter = 0;
        for(auto ch:events){
            if(counter>=10) break;
            if(isdigit(ch[0])) 
            {
                int number = stoi(ch);
                score+=number;
            }else if(ch == "W") counter+=1;
            else{
                score+=1;
            }
        }
        vector<int>ans;
        ans.push_back(score);
        ans.push_back(counter);
        return ans;
    }
};