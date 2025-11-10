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
        int idx;
        while(q.size()>0)
        {
            idx = 0;
            int n = q.size();
            unsigned long long  stIdx = q.front().second;
            unsigned long long endIdx = q.back().second;
            maximum = max(maximum,(int)(endIdx-stIdx+1));//formula for width
            for(int  i = 0;i<n;i++)
            {
                auto currNode = q.front();
                q.pop();
                if(currNode.first->left) q.push({currNode.first->left,2*currNode.second+1}); //CBT indexing for left node forumula
                if(currNode.first->right)q.push({currNode.first->right,2*currNode.second+2});

            }

        }
        return  maximum;
    }
};