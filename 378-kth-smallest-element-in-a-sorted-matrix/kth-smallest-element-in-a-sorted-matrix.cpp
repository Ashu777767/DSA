class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
    int n = matrix.size();

    priority_queue<
        pair<int, pair<int,int>>,
        vector<pair<int, pair<int,int>>>,
        greater<>
    > pq;

    // Step 1: push first column
    for(int i = 0; i < n; i++) {
        pq.push({matrix[i][0], {i, 0}});
    }

    // Step 2: process k elements
    while(k--) {
        auto top = pq.top();
        pq.pop();

        int val = top.first;
        int r = top.second.first;
        int c = top.second.second;

        if(c + 1 < n) {
            pq.push({matrix[r][c+1], {r, c+1}});
        }

        if(k == 0) return val;
    }

    return -1;
}
};