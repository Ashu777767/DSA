class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        //dekh tu jo brute force socha woh saki toh hai lekin woh tle marega maybe kyu t.c sahi nhi hai
        unordered_map<int,int>freq;
        for(auto n:nums){
            freq[n]++;      //har number ka freq store hogya
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;   //min heap
        for(auto &it:freq){
            pq.push({it.second,it.first});   //k elements lega aur use store karega desecending order mai as per freq 
            if(pq.size()>k) pq.pop(); //so that chotta freq remove hojayega
        }
          vector<int>ans;
        while(!pq.empty()){
           ans.push_back(pq.top().second);
           pq.pop();
        }

         return ans;
    }
};