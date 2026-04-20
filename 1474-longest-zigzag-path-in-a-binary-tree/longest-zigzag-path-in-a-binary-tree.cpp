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
    int maxi = 0;

    void dfs(TreeNode* node, int leftLen, int rightLen) {
        if (!node) return;

        // update answer
        maxi = max(maxi, max(leftLen, rightLen));

        // go left → last move becomes LEFT
        dfs(node->left, 0, leftLen + 1);

        // go right → last move becomes RIGHT
        dfs(node->right, rightLen + 1, 0);
    }

    int longestZigZag(TreeNode* root) {
        dfs(root, 0, 0);
        return maxi;
    }
};