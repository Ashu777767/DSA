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
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0,head);
        ListNode* slowptr = dummy;
        ListNode* fastptr = head;
        for(int i = 0;i<n;i++){
            fastptr = fastptr->next;
        }
        while(fastptr != NULL){
            fastptr = fastptr->next;
            slowptr = slowptr->next;
        }
        ListNode* del = slowptr->next;
        slowptr->next = slowptr->next->next;
        delete del;
        return dummy->next; 
    }
};