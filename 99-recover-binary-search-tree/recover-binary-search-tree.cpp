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
void correct(TreeNode* &root,int data1,int data2)
{
  if(root == NULL)
  return ;

  if(root->val == data1 || root->val == data2){
    root->val = (root->val == data1)?data2:data1;
  }
  
  correct(root->left,data1,data2);
  correct(root->right,data1,data2);
}
void inorder(TreeNode* root,vector<int>& arr1){
    if(root == NULL){
        return ;
    }
    inorder(root->left,arr1);
    arr1.push_back(root->val);
    inorder(root->right,arr1);
}
    void recoverTree(TreeNode* root) {
        vector<int>arr1;
        inorder(root,arr1);
        vector<int>copy = arr1;
        sort(copy.begin(),copy.end());
        int data1,data2;
        for(int i = 0;i<arr1.size();i++){
            if(arr1[i] != copy[i]){
                    data1 = arr1[i];
                    data2 = copy[i];
                    break;
            }
        }
        correct(root,data1,data2);

    }
};