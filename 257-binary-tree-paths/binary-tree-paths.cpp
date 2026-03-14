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
bool helper(TreeNode* root,vector<string> &ans,string path){
    if(root == NULL) return true;
    path+= to_string(root->val);
    bool left = helper(root->left,ans,path+"->");
    bool right = helper(root->right,ans,path+"->");

    if(left && right) ans.push_back(path);
    return false;
}
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>ans;
        string path;
        helper(root,ans,path);
        return ans;
    }
};