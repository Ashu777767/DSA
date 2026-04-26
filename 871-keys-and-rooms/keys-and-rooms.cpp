class Solution {
public:
 bool dfs(vector<vector<int>>& rooms,vector<int> &vis,int src){
   vis.push_back(src); 
   if (vis.size() == rooms.size()) return true;  
      for(auto k:rooms[src]){
        if(find(vis.begin(), vis.end(), k) == vis.end()){
          if(dfs(rooms,vis,k)){
            return true;
          }
        }
      }
      return false;
    
 }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<int>vis;
      return  dfs(rooms,vis,0);
    }
};