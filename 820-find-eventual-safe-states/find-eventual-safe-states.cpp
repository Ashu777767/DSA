class Solution {
public:
bool safeNode(int src,vector<bool> &vis,vector<bool>&isSafe,vector<vector<int>>& graph,bool flag){
    vis[src] = true;
    for(auto node:graph[src]){
        if(!vis[node] && !isSafe[node]){
            if(safeNode(node,vis,isSafe,graph,true)){
                isSafe[node] = true;
            }else{
                flag = false;
            }
        }else if(!isSafe[node]){
            flag = false;

        }
    }
    return flag;
}
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<bool>isSafe(n,false);
        vector<bool>vis(n,false);
        for(int i = 0;i<n;i++){  //marking terminal nodes
            if(graph[i].size() == 0){
                isSafe[i] = true;
                vis[i] = true;
            }
        }
        for(int i = 0;i<n;i++){
            if(!vis[i]){
                if(safeNode(i,vis,isSafe,graph,true)){
                    isSafe[i] = true;
                }
            }
        }
        vector<int>ans;
        for(int  i = 0;i<n;i++){
            if(isSafe[i]){
                ans.push_back(i);
            }
        }
        return ans;

    }
};