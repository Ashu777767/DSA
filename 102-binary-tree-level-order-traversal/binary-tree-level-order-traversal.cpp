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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == NULL) return {};
        vector<vector<int>>ans;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            vector<int>level; //instead ans.push_back(vector<int>()) this creates new level insead of temporary level then down is there
            int size = q.size();
            for(int i = 0;i<size;i++){
                TreeNode* temp = q.front();
                q.pop();
                level.push_back(temp->val); //as 2d array ke liye hum directly ans mai nhi push karsakte isliye tempororay banaana padtha hai aur bhi ways hai like ans.back().push_back(temp->val) this was alterantive

                if(temp->left) q.push(temp->left);
                if(temp->right)q.push(temp->right);
            }
            ans.push_back(level);
        }
        return ans;
    }
};