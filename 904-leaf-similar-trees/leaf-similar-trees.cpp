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
    void getleafnodes(TreeNode* root, vector<int>& node_list) {
        if (!root) {
            return;
        }
        if (!root->left && !root->right) {
            node_list.push_back(root->val);
            return;
        }
        getleafnodes(root->left, node_list);
        getleafnodes(root->right, node_list);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> node_list1, node_list2;
        getleafnodes(root1, node_list1);
        getleafnodes(root2, node_list2);
        return node_list1 == node_list2;
    }
};