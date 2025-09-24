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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
    //creates a dummy
        ListNode* dummy = new ListNode(0,head); //next = head val = 0
     //marks the previous and starting node to reverse
        ListNode* leftpre = dummy;  //if left = 1 then we need a prev node so we use this
        ListNode* curr = head;
        for(int i = 0;i<left-1;i++){
            leftpre = leftpre->next;
            curr = curr->next;
        }
        ListNode*startMergeNode = curr;
    //reverseing the given part
        ListNode* prev = NULL;
        ListNode* Next = NULL;
        for(int i = 0;i<(right-left+1);i++){
            Next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = Next;
        }
    //now linking the starting and ending to reversed list
        //links 1->4
        leftpre->next = prev;
        //links the 2 ->5
        startMergeNode->next = curr;
        
        //return the list 
        return dummy->next;
    }
};