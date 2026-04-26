class Solution {
public:
    void dfs(vector<vector<int>>& rooms, vector<bool>& vis, int src) {
        vis[src] = true;

        for (auto k : rooms[src]) {
            if (!vis[k]) {
                dfs(rooms, vis, k);
            }
        }
    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> vis(n, false);

        dfs(rooms, vis, 0);

        for (bool v : vis) {
            if (!v)
                return false;
        }
        return true;
    }
};