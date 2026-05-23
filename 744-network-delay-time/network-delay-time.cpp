class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // transforming it to the organized vertices and edges
        vector<vector<pair<int, int>>> adj(n + 1);
        for (auto& e : times) {
            adj[e[0]].push_back({e[1], e[2]});
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq; // min heap
        vector<int> dist(n + 1, INT_MAX);
        vector<int> vis(n + 1, 0);
        pq.push({0, k}); // dist,node
        //edge initalize source to 0 dist
        dist[k] = 0;
        while (!pq.empty()) {
            int u = pq.top().second;
            int dis = pq.top().first;
            pq.pop();
            if (vis[u] == 1)
                continue;
            for (auto& Edge : adj[u]) {
                int node = Edge.first;
                int d = Edge.second;
                if (dist[node] > dis + d) {
                    dist[node] = dis + d;
                    pq.push({dist[node], node});
                }
            }
            vis[u] = 1;
        }
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (dist[i] == INT_MAX)
                return -1;
            else
                ans = max(ans, dist[i]);
        }
        return ans;
    }
};