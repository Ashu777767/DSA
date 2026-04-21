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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int maxSum = INT_MIN;
        int level = 1;
        int maxlevel = 1;
        while (!q.empty()) {
            int size = q.size();
            int sum = 0;
            while (size > 0) {
                TreeNode* node = q.front();
                sum += node->val;
                q.pop();

                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
                size--;
            }
            if (sum > maxSum) {
                maxSum = sum;
                maxlevel = level;
            }
            level++;
        }
        return maxlevel;
    }
};