class Solution {
public:
void findcombination(vector<vector<int>>& ans,int k,int n,int sum,vector<int>temp,int index){
    if(temp.size() == k &&sum == n){
        ans.push_back(temp);
        return ;
    }
     if(temp.size() >= k || sum >= n || index>9){
        return ;
    }
    for(int i =index;i<=9;i++){
        sum+=i;
        temp.push_back(i);
        findcombination(ans,k,n,sum,temp,i+1);
        sum-=i;
        temp.pop_back();
    }


}
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>ans;
        vector<int>temp;
        findcombination(ans,k,n,0,temp,1);
        return ans;
    }
};