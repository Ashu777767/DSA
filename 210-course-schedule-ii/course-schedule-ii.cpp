class Solution {
public:
bool isCycleDFS(int src,int n,vector<vector<int>> &prerequisites,vector<bool>& vis,vector<bool>&recPath,stack<int>& st){
    vis[src] = true;
    recPath[src] = true;
    for(int i = 0;i<prerequisites.size();i++){
        int v = prerequisites[i][0];
        int u = prerequisites[i][1];
        if(u == src){
            if(!vis[v]){
            if(isCycleDFS(v,n,prerequisites,vis,recPath,st)) return true;
            }
            else if(recPath[v]){
                  return true;
            }
        }
    }
    recPath[src] = false;
    st.push(src);
    return false;

}
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<bool>vis(numCourses,false);
        vector<bool>recPath(numCourses,false);
        stack<int>st;
        for(int i = 0;i<numCourses;i++){
           if(!vis[i]){
            if(isCycleDFS(i,numCourses,prerequisites,vis,recPath,st)){
                return {};
            }
           }
        }
        vector<int>ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        return ans;

    }
};