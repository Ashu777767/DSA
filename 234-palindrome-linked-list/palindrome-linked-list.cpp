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
     ListNode* reversell(ListNode* slow){  //reverse function call
        ListNode* prev = NULL;
        ListNode* curr = slow;
        ListNode* next = NULL;
        while(curr!= NULL){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
     }

    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast!= NULL && fast->next!= NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
     ListNode* secondPart =  reversell(slow);
     ListNode* firstPart = head;
     while(secondPart != NULL){
        if(secondPart->val != firstPart->val) return false;
        firstPart = firstPart->next;
        secondPart = secondPart->next;
     }
     return true;
    }
};