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
     int idx = 0;
     TreeNode* treebuild(vector<int>& preorder, vector<int>& inorder,int left,int right,unordered_map<int,int>& mp){
     if(left>right) return NULL;
     TreeNode* root = new TreeNode(preorder[idx]);
     int  inidx = mp[preorder[idx++]];
     root->left = treebuild(preorder,inorder,left,inidx-1,mp);
     root->right = treebuild(preorder,inorder,inidx+1,right,mp);
      return root;
     }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
       unordered_map<int,int>mp;
       for(int i = 0;i<inorder.size();i++){
        mp[inorder[i]] = i;
       }
       return treebuild(preorder,inorder,0,inorder.size()-1,mp);
    }
};