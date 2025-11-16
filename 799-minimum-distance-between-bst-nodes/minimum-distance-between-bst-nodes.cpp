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
  TreeNode* prev = NULL;
    int minDiffInBST(TreeNode* root) {
        int ans = INT_MAX;
        if(root == NULL) return INT_MAX;
        
        int leftmin = minDiffInBST(root->left);
        if(prev != NULL){
            ans = min(ans,(root->val-prev->val));
        }
        prev = root;
        
        int rightmin = minDiffInBST(root->right);
             
        ans = min(ans,(min(leftmin,rightmin)));
        return ans;
    }
};