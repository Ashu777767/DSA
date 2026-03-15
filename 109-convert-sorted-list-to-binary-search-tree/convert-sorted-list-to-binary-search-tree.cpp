/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
ListNode* findmid(ListNode* stnode,ListNode* endNode){
    ListNode* slow = stnode;
    ListNode* fast = stnode;
    while(fast!=endNode && fast->next != endNode){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
TreeNode* BST(ListNode* stnode,ListNode* endNode){
     if(stnode == endNode) return NULL;
    ListNode* midNode = findmid(stnode,endNode);
    TreeNode* root = new TreeNode(midNode->val);
    root->left = BST(stnode,midNode);
    root->right = BST(midNode->next,endNode);
    return root;
}
    TreeNode* sortedListToBST(ListNode* head) {
        return BST(head,NULL);
    }
};