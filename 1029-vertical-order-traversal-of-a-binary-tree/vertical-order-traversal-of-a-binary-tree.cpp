/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>>ans;
        queue<pair<TreeNode*,pair<int,int>>>q;
        q.push({root,{0,0}});
        map<int,map<int,multiset<int>>>node;
        while(!q.empty()){
         auto temp = q.front();
         q.pop();
         TreeNode* dummy = temp.first;
         int row = temp.second.second;
         int col = temp.second.first;
         node[col][row].insert(dummy->val);
         if(dummy->left) q.push({dummy->left,{col-1,row+1}});
         if(dummy->right)q.push({dummy->right,{col+1,row+1}});

        }
        for(auto &q:node){
            vector<int>eachcol;
            for(auto &p:q.second){
                  eachcol.insert(eachcol.end(),p.second.begin(),p.second.end());
            
            }
            ans.push_back(eachcol);
        }
        return ans;
    }
};