/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL)
        {
            return NULL;

        }
        if(root->val == p->val || root->val == q->val){
        return root; //LCA
        }
        TreeNode* leftTree = lowestCommonAncestor(root->left,p,q);
        TreeNode* RightTree = lowestCommonAncestor(root->right,p,q);
        if(leftTree && RightTree){  //LCA found cause both p and q found
            return root;
        }
        else if(leftTree){
            return leftTree;
        }
        else{
            return RightTree;
        }
        
    }
};