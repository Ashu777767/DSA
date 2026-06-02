class Solution {
public:
    vector<int> parent;
    vector<int> rank;

    int find(int x) {
        if(parent[x] == x)
            return x;

        return parent[x] = find(parent[x]); // Path Compression
    }

    void Union(int x, int y) {
        int px = find(x);
        int py = find(y);

        if(px == py)
            return;

        // Union by Rank
        if(rank[px] < rank[py]) {
            parent[px] = py;
        }
        else if(rank[px] > rank[py]) {
            parent[py] = px;
        }
        else {
            parent[py] = px;
            rank[px]++;
        }
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {

        int n = edges.size();

        parent.resize(n + 1);
        rank.resize(n + 1, 0);

        for(int i = 1; i <= n; i++) {
            parent[i] = i;
        }

        for(auto &e : edges) {

            int u = e[0];
            int v = e[1];

            if(find(u) == find(v))
                return e;

            Union(u, v);
        }

        return {};
    }
};