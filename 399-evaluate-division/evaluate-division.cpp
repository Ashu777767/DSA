class Solution {
public:
    double dfs(string src, string des,
           unordered_map<string, vector<pair<string, double>>>& adj,
           unordered_set<string>& vis,
           double dist) {

    if(src == des)
        return dist;

    vis.insert(src);

    for(auto &it : adj[src]) {
        string ch = it.first;
        double dis = it.second;

        if(vis.count(ch))
            continue;

        double ans = dfs(ch, des, adj, vis, dist * dis);

        if(ans != -1.0)
            return ans;
    }

    return -1.0;
}

    vector<double> calcEquation(vector<vector<string>>& equations,
                                vector<double>& values,
                                vector<vector<string>>& queries) {
        unordered_map<string, vector<pair<string, double>>> adj;
        unordered_set<string> s;
        int size = equations.size();
        for (int i = 0; i < size; i++) {
            string char1 = equations[i][0];
            string char2 = equations[i][1];
            double val = values[i];
            double reversedist = 1 / values[i];
            adj[char1].push_back({char2, val});
            adj[char2].push_back({char1, reversedist});
            if (!s.count(char1)) {
                s.insert(char1);
            }
            if (!s.count(char2)) {
                s.insert(char2);
            }
        }
        int len = queries.size();
        vector<double> answer(len, -1.00000);
        for (int i = 0; i < len; i++) {
            unordered_set<string> vis;
            string src = queries[i][0];
            string des = queries[i][1];
           if (!s.count(src) || !s.count(des))
                continue;
            else if(src == des) answer[i] = 1.00000;

            else {
                double ans = dfs(src, des, adj, vis, 1.0);
                answer[i] = ans;
            }
        }
        return answer;
    }
};