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
    int pairSum(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        // reverse the second half
        ListNode* sechead = slow->next;
        slow->next = NULL;
        ListNode* prev = NULL;
        ListNode* curr = sechead;
        ListNode* Next = NULL;
        while (curr) {
            Next = curr->next;
            curr->next = prev;
            prev = curr; // prev has the final after mid head;
            curr = Next;
        }
        ListNode* tailHead = prev;
        int maximum = 0;
        while (head) {
            int sum = head->val + tailHead->val;
            maximum = sum > maximum ? sum : maximum;
            head = head->next;
            tailHead = tailHead->next;
        }
        return maximum;
    }
};