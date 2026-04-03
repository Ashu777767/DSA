class Solution {
public:
bool isCycleDFS(int src, vector<bool>& vis, vector<bool>& recPath, vector<vector<int>>& adj) {
    
    vis[src] = true;
    recPath[src] = true;

    for(int i =0;i<adj.size();i++) {
          int v = adj[i][0];//put any value cuz in main function we are checking from every staring point
          int u = adj[i][1];
        // Case 1: Not visited → go deeper
        if(u == src){
        if(!vis[v]) {
            if(isCycleDFS(v, vis, recPath, adj)) {
                return true;
            }
        }
        

        // Case 2: Already in recursion path → cycle
        else if(recPath[v]) {
            return true;
        }
        }
    }

    // Backtracking step
    recPath[src] = false;

    return false;
}
    bool canFinish(int n, vector<vector<int>>& edges) {
        vector<bool>vis(n,false);
        vector<bool>recPath(n,false);
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                if (isCycleDFS(i, vis, recPath, edges)) {
                    return false;
                }
            }
        }
        return true;
    }
};