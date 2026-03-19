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
void hasPathSum(TreeNode* root,int targetSum,vector<vector<int>>& ans,vector<int>& path){
       if(root == NULL) return ;

        path.push_back(root->val);
         if(targetSum == root->val && root->left == NULL && root->right == NULL)  {
            ans.push_back(path);
         }
         hasPathSum(root->left,targetSum-root->val,ans,path);
         hasPathSum(root->right,targetSum-root->val,ans,path);
        path.pop_back();
       return ;
}

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>ans;
        vector<int>path;
        hasPathSum(root,targetSum,ans,path);
        return ans;
    }
};