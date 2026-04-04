class Solution {
public:

bool isCycleDFS(int src, vector<vector<int>>& adj,
                vector<bool>& vis, vector<bool>& recPath,
                stack<int>& st) {

    vis[src] = true;
    recPath[src] = true;

    for(auto v : adj[src]) {
        if(!vis[v]) {
            if(isCycleDFS(v, adj, vis, recPath, st)) return true;
        }
        else if(recPath[v]) {
            return true;
        }
    }

    recPath[src] = false;
    st.push(src);
    return false;
}

vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

    vector<vector<int>> adj(numCourses);

    // build graph
    for(auto &p : prerequisites) {
        adj[p[1]].push_back(p[0]);
    }

    vector<bool> vis(numCourses, false);
    vector<bool> recPath(numCourses, false);
    stack<int> st;

    for(int i = 0; i < numCourses; i++) {
        if(!vis[i]) {
            if(isCycleDFS(i, adj, vis, recPath, st)) {
                return {};
            }
        }
    }

    vector<int> ans;
    while(!st.empty()) {
        ans.push_back(st.top());
        st.pop();
    }

    return ans;
}
};