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
    ListNode* reverseList(ListNode* head) {
        ListNode* currP = head;
        ListNode* prev = NULL;
        ListNode* Next = NULL;
        while(currP != NULL){
            Next = currP->next;
            currP->next = prev;
            prev = currP;
            currP = Next;
        }
         
         return prev;
    }
};