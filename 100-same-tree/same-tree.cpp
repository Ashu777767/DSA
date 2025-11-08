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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == NULL && q == NULL) return true; //if both are NULL
        if(p == NULL || q==NULL) return false;  //if both any one is NULL then false
        if(p->val != q->val) return false;   //if value are not equal the false
        bool left = isSameTree(p->left,q->left);  //same find for left and right
        bool right = isSameTree(p->right,q->right);
        return left && right;  //return true if both true
        
    }
};