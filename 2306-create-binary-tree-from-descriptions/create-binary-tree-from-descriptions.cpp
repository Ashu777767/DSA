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
TreeNode* formbinarytree(unordered_map<int,vector<pair<int,int>>> &mp,int node){
    TreeNode* root = new TreeNode(node);
    for(auto &it:mp[node]){
        int child = it.first;
        int isLeft = it.second;
        if(isLeft == 1){
            root->left = formbinarytree(mp,child);
        }
        if(isLeft == 0){
            root->right = formbinarytree(mp,child);
        }
    }
    return root;

}
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int,vector<pair<int,int>>>mp;
        unordered_set<int>s;
        for(auto &it:descriptions){
            mp[it[0]].push_back({it[1],it[2]});
            s.insert(it[1]);
            // s.insert(it[2]);
        }
        int node;
        for(auto &it:descriptions){
            if(!s.count(it[0])) {
                node = it[0];
                break;
            }
        }
        return formbinarytree(mp,node);
    }
};