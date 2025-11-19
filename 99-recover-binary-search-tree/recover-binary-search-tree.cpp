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
    TreeNode *first = NULL, *second = NULL, *prev = new TreeNode(INT_MIN);

    void recoverTree(TreeNode* root) {
        TreeNode* curr = root;

        while(curr != NULL) {

            // 1) If left is NULL → process this node & go right
            if(curr->left == NULL) {

                // violation check
                if(prev && curr->val < prev->val) {
                    if(!first) first = prev;
                    second = curr;
                }
                prev = curr;

                curr = curr->right;
            }

            // 2) If left exists → find inorder predecessor
            else {
                TreeNode* pred = curr->left;

                while(pred->right && pred->right != curr)
                    pred = pred->right;

                // Case A: Create the thread
                if(pred->right == NULL) {
                    pred->right = curr;
                    curr = curr->left;
                }

                // Case B: Thread already exists → remove it
                else {
                    pred->right = NULL;

                    // violation check again
                    if(prev && curr->val < prev->val) {
                        if(!first) first = prev;
                        second = curr;
                    }
                    prev = curr;

                    curr = curr->right;
                }
            }
        }

        // swap the faulty values
        swap(first->val, second->val);
    }
};
