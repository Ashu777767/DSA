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
    ListNode* oddEvenList(ListNode* head) {
        if (head == NULL || head->next == NULL || head->next->next == NULL)
            return head;
        ListNode* evenNode = head; // 0-based indexxing
        ListNode* oddhead = head->next;
        ListNode* oddNode = oddhead;
        while (evenNode->next && evenNode->next->next) {
            evenNode->next = evenNode->next->next;
            evenNode =
                evenNode->next; // only one movee naa 1->3 then it will movee
            if (evenNode->next) {
                oddNode->next = evenNode->next;
                oddNode = evenNode->next;
            } else {
                oddNode->next = NULL;
            }
        }
        evenNode->next = oddhead;
        return head;
    }
};