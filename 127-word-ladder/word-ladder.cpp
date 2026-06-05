class Solution {
public:
    int ladderLength(string beginWord, string endWord,
                     vector<string>& wordList) {

        unordered_set<string> st(wordList.begin(), wordList.end());

        if(st.find(endWord) == st.end())
            return 0;

        queue<pair<string,int>> q;
        q.push({beginWord, 1});

        st.erase(beginWord);

        while(!q.empty()) {

            string curr = q.front().first;
            int transformation = q.front().second;
            q.pop();

            if(curr == endWord)
                return transformation;

            for(int i = 0; i < curr.size(); i++) {

                char original = curr[i];

                for(char ch = 'a'; ch <= 'z'; ch++) {

                    curr[i] = ch;

                    if(st.find(curr) != st.end()) {

                        q.push({curr, transformation + 1});

                        st.erase(curr); // mark visited
                    }
                }

                curr[i] = original;
            }
        }

        return 0;
    }
};