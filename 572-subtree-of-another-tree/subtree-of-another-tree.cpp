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
bool check(TreeNode* root, TreeNode* subRoot){
    if(root == NULL || subRoot == NULL){
        return root == subRoot; //if both null returns true if either one null returns false
    }
    bool leftn = check(root->left,subRoot->left);
    bool rightn = check(root->right,subRoot->right);
     
    return leftn && rightn && (root->val == subRoot->val);  //returns true if left right and root are same
}
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root == NULL) return false;
        if(root->val == subRoot->val){
             if(check(root,subRoot))return true;
        }

    bool leftnode = isSubtree(root->left,subRoot);
    bool rightnode = isSubtree(root->right,subRoot);
        
        return leftnode || rightnode;
        
    }
};