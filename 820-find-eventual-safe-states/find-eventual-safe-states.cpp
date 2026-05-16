class Solution {
public:
bool safeNode(int src,vector<bool> &vis,vector<bool>&isSafe,vector<vector<int>>& graph,bool flag){
    vis[src] = true;
    for(auto node:graph[src]){
        if(!vis[node] && !isSafe[node]){
            if(safeNode(node,vis,isSafe,graph,true)){
                isSafe[node] = true;
            }else{
                flag = false; //if one adjcent node found non safe the the vertex is not valid
            }
        }else if(!isSafe[node]){ //if one adjcent node is vis and not safe means not valid vertex for answer
            flag = false;

        }
    }
    return flag;
}
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<bool>isSafe(n,false);
        vector<bool>vis(n,false);
        for(int i = 0;i<n;i++){  //marking terminal nodes at first
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