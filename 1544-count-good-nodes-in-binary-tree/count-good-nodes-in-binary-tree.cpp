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
    void findgoodnodes(TreeNode* root, int& count, int max) {
        if (!root) {
            return;
        }
        if (root->val >= max) {
            count++;
            findgoodnodes(root->left, count, root->val);
            findgoodnodes(root->right, count, root->val);
        } else {
            findgoodnodes(root->left, count, max);
            findgoodnodes(root->right, count, max);
        }
    }
    int goodNodes(TreeNode* root) {
        int count = 0;
        int max = root->val;
        findgoodnodes(root, count, max);
        return count;
    }
};