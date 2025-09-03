class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int len = temperatures.size();
        vector<int>ans(len,0);
        stack<pair<int,int>>s;
        for(int i = 0;i<len;i++){
            while((!s.empty()) && s.top().first<temperatures[i] ){       //case1 founds the warmer day
                ans[s.top().second] = i-s.top().second;
                s.pop();
            }
            s.emplace(temperatures[i],i);

        }
        return ans;
    }
};