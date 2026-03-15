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

ListNode* curr;

TreeNode* build(int left,int right){

    if(left>right)
        return NULL;

    int mid = (left+right)/2;

    // build left subtree
    TreeNode* leftChild = build(left,mid-1);

    // current node becomes root
    TreeNode* root = new TreeNode(curr->val);

    root->left = leftChild;

    curr = curr->next;

    // build right subtree
    root->right = build(mid+1,right);

    return root;
}

TreeNode* sortedListToBST(ListNode* head) {

    int n=0;
    ListNode* temp=head;

    while(temp){
        n++;
        temp=temp->next;
    }

    curr = head;

    return build(0,n-1);
}
};