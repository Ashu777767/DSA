class Solution {
public:
    struct cmp {
        bool operator()(pair<string,int>& a, pair<string,int>& b) {
            // Case 1: same frequency
            if(a.second == b.second) {
                return a.first < b.first; 
                // lexicographically smaller → lower priority (will go down)
            }
            // Case 2: different frequency
            return a.second > b.second; 
            // higher freq → lower priority (we want to keep it)
        }
    };

    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> freq;

        // Step 1: count frequency
        for(string w : words) {
            freq[w]++;
        }

        // Step 2: min heap
        priority_queue<
            pair<string,int>,
            vector<pair<string,int>>,
            cmp
        > pq;

        for(auto &it : freq) {
            pq.push(it);

            if(pq.size() > k) {
                pq.pop();
            }
        }

        // Step 3: extract answer
        vector<string> ans;
        while(!pq.empty()) {
            ans.push_back(pq.top().first);
            pq.pop();
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};