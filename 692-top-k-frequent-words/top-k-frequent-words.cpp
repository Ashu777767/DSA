class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> freq;

        // Step 1: count frequency
        for(string w : words) {
            freq[w]++;
        }

        int n = words.size();

        // Step 2: bucket (index = frequency)
        vector<vector<string>> bucket(n + 1);

        for(auto &w : freq) {
            bucket[w.second].push_back(w.first);
        }

        // Step 3: traverse from high freq
        vector<string> ans;

        for(int i = n; i >= 0 && ans.size() < k; i--) {
            
            if(!bucket[i].empty()) {
                //  VERY IMPORTANT
                sort(bucket[i].begin(), bucket[i].end());

                for(string &word : bucket[i]) {
                    ans.push_back(word);
                    if(ans.size() == k) break;
                }
            }
        }

        return ans;
    }
};