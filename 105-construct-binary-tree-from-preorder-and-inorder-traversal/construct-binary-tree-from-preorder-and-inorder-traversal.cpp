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
//   int search(int val,vector<int>& inorder,int left,int right){
//     for(int i = left;i<=right;i++)
//     {
//         if(inorder[i] == val){
//             return i;
//         }
//     }
//     return -1; //it will not come because due to constrainsts
//   }

   TreeNode* helper(vector<int>& preorder, vector<int>& inorder,int& idx,int left,int right,unordered_map<int,int>& mp){
     if(left>right) return NULL;

      TreeNode* root = new TreeNode(preorder[idx]);
      int inIdx = mp[preorder[idx]];  //better t.c
      idx++;
      root->left = helper(preorder,inorder,idx,left,inIdx-1,mp);
      root->right = helper(preorder,inorder,idx,inIdx+1,right,mp);

      return root;
   }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int idx = 0;
        unordered_map<int,int>mp;
        for(int i = 0;i<inorder.size();i++)
        {
            mp[inorder[i]] = i;
        }
     return helper(preorder,inorder,idx,0,inorder.size()-1,mp);
    }
};