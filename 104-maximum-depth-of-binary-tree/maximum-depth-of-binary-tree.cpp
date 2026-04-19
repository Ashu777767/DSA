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
     int height = 0;
     int maximum = 0;
    int maxDepth(TreeNode* root) {
        if(root == NULL){
            maximum = max(height,maximum);
            return maximum;
        }
        height++;
        maxDepth(root->left);
        maxDepth(root->right);
        height--;
        return maximum;
    }
};