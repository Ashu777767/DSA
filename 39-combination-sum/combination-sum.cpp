class Solution {
public:
     set<vector<int>>s;
    void getAllcombinations(vector<int>& arr,int target,int idx,vector<vector<int>>&ans,vector<int>& combi)
    {
        if(idx == arr.size() ||target<0){  //if all values of canditate are over or target becomes minus then we should stop and return
            return ;
        }

        if(target == 0){    //solution base case
        if(s.find({combi}) == s.end()){  //using set for only uniquee answers
            ans.push_back({combi});
            s.insert({combi});
        }
           return ;
        }
         
        combi.push_back(arr[idx]);   //->inclding for both single and multiple inclusion
      //single inclusion
        getAllcombinations(arr,target-arr[idx],idx+1,ans,combi);
        //multiple
        getAllcombinations(arr,target-arr[idx],idx,ans,combi);
        //exclusion
        combi.pop_back(); //backtrack step can be assumed
        getAllcombinations(arr,target,idx+1,ans,combi);  // as we are not including anything so here we don't subract from target
        

    }
    vector<vector<int>> combinationSum(vector<int>& arr, int target) {
        vector<vector<int>>ans;
        vector<int>combi;
        getAllcombinations(arr,target,0,ans,combi);
        return ans;
    }
};