class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        
        int n = graph.size();

        // reverse graph
        vector<vector<int>> revGraph(n);

        // outdegree count
        vector<int> outDegree(n, 0);

        // Build reverse graph
        for(int i = 0; i < n; i++) {

            outDegree[i] = graph[i].size();

            for(auto node : graph[i]) {
                revGraph[node].push_back(i);
            }
        }

        queue<int> q;

        // terminal nodes -> outdegree = 0
        for(int i = 0; i < n; i++) {
            if(outDegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> safeNodes;

        // Kahn's Algorithm
        while(!q.empty()) {

            int node = q.front();
            q.pop();

            safeNodes.push_back(node);

            // visit parents
            for(auto parent : revGraph[node]) {

                outDegree[parent]--;

                if(outDegree[parent] == 0) {
                    q.push(parent);
                }
            }
        }

        // answer should be sorted
        sort(safeNodes.begin(), safeNodes.end());

        return safeNodes;
    }
};