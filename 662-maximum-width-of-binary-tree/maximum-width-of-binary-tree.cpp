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
    int widthOfBinaryTree(TreeNode* root) {
        int maximum = 0;
        queue<pair<TreeNode*,unsigned long long>>q;
        q.push({root,0});
        while(!q.empty()){
            int n = q.size();
            unsigned long long startIdx = q.front().second;
           unsigned long long endIdx = q.back().second;
            maximum = max(maximum,(int)(endIdx-startIdx+1));
            while(n--){
                auto curr = q.front();
                q.pop();
                if(curr.first->left){
                    q.push({curr.first->left,2*curr.second+1});
                }
                if(curr.first->right){
                     q.push({curr.first->right,2*curr.second+2});
                }
     
            }

        }
       return maximum;
    }
};