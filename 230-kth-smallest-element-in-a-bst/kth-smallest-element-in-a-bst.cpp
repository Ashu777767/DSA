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
    int cnt = 0;
    int ans  = -1;
    bool found = false;
    void helper(TreeNode* root){
        if(root == NULL) return ;
        helper(root->left);
        if(found) return ;
        if(cnt == 1){
        ans = root->val;
        found = true;
        return;
        }
        cnt--;
        helper(root->right);
    }
    int kthSmallest(TreeNode* root, int k) {
        cnt = k;
        helper(root);
        return ans;

    }
};