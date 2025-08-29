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
     ListNode* reversell(ListNode* slow){  
        ListNode* prev = NULL;
        ListNode* curr = slow->next;  
        ListNode* next = NULL;
        while(curr!= NULL){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;   
     }
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* secondPart =  reversell(slow);
        slow->next = NULL;// to break the cylce because at last if not done 3 will have 4 and 4 will 3 so it forms a cycle and tle error
        ListNode* firstPart =  head;
        ListNode*Next = NULL;
        ListNode*Next2 = NULL;

        while(secondPart != NULL){
            Next = firstPart->next;
            Next2 = secondPart->next;
            secondPart->next = Next;  //merge
            firstPart->next = secondPart;
            firstPart = Next;
            secondPart = Next2;
        }
        
    }
};