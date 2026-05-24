class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights,
                          int src, int dst, int k) {

        vector<vector<pair<int,int>>> adj(n);

        for(auto &v : flights){
            adj[v[0]].push_back({v[1], v[2]});
        }

        vector<int> dist(n, INT_MAX);

        queue<pair<int,pair<int,int>>> q;
        // {stops,{node,cost}}

        q.push({0,{src,0}});
        dist[src] = 0;

        while(!q.empty()){

            auto it = q.front();
            q.pop();

            int stops = it.first;
            int node  = it.second.first;
            int cost  = it.second.second;

            if(stops > k) continue;

            for(auto &edge : adj[node]){

                int adjNode = edge.first;
                int price   = edge.second;

                if(cost + price < dist[adjNode]
                   && stops <= k){

                    dist[adjNode] = cost + price;

                    q.push({stops + 1,
                           {adjNode, dist[adjNode]}});
                }
            }
        }

        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};