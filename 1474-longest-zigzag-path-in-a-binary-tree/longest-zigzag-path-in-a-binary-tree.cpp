/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int findmaxpath(TreeNode* root, char ch, int vis) {
        if (!root) {
            return vis;
        }
        vis++;
        int zigzaglen = ch == 'L' ? findmaxpath(root->right, 'R', vis)
                                  : findmaxpath(root->left, 'L', vis);

        return zigzaglen;
    }
    int helper2(TreeNode* root) {
        int vis = 0;
        int leftmax = findmaxpath(root->left, 'L', vis);
        int rightmax = findmaxpath(root->right, 'R', vis);
        return max(leftmax, rightmax);
    }
    int helper(TreeNode* root) {
        if (!root) {
            return 0;
        }
        int zigzag = helper2(root);
        int leftnode = helper(root->left);
        int rightnode = helper(root->right);
        int length = max(leftnode, rightnode);
        return max(zigzag, length);
    }
    int longestZigZag(TreeNode* root) { return helper(root); }
};