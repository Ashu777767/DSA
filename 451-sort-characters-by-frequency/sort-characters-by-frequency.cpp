class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int>mp;
        for(char c:s){
            mp[c]++;
        }
        priority_queue<pair<int,char>>pq;
        for(auto val:mp){
            pq.push({val.second,val.first});
        }
        string ans;
        while(!pq.empty()){
            char c = pq.top().second;
            int freq = pq.top().first;
            pq.pop();
           ans.append(freq, c);
        }
        return ans;
    }
};