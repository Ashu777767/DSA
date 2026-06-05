class Solution {
public:
    int ladderLength(string beginWord, string endWord,
                     vector<string>& wordList) {

        if (find(wordList.begin(), wordList.end(), endWord) == wordList.end())
            return 0;

        int esize = endWord.size();
        int size = wordList.size();

        unordered_set<string> vis;

        queue<pair<string, int>> q;

        q.push({beginWord, 1});
        vis.insert(beginWord);

        while (!q.empty()) {

            string curr = q.front().first;
            int transformation = q.front().second;
            q.pop();

            if (curr == endWord)
                return transformation;

            for (int i = 0; i < size; i++) {

                string word = wordList[i];

                if (vis.count(word))
                    continue;

                int count = 0;

                for (int index = 0; index < esize; index++) {
                    if (word[index] != curr[index])
                        count++;
                }

                if (count == 1) {
                    q.push({word, transformation + 1});
                    vis.insert(word);
                }
            }
        }

        return 0;
    }
};