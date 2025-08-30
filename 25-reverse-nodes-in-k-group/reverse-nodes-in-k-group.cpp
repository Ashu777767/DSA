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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) return head;

        ListNode* dummy = new ListNode(0, head);
        ListNode* leftpre = dummy;
        ListNode* temp = head;

        ListNode* counterk = head; // counting node
        int count = 0;

        while (counterk != NULL) {
            count++;
            // When k nodes completed → reverse
            if (count == k) {
                // Reverse k nodes starting from temp
                ListNode* subhead = temp;
                ListNode* prev = NULL;
                ListNode* curr = temp;
                ListNode* Next = NULL;

                for (int i = 0; i < k; i++) {
                    Next = curr->next;
                    curr->next = prev;
                    prev = curr;
                    curr = Next;
                }

                // reconnect
                leftpre->next = prev;
                subhead->next = curr;

                // move pointers
                leftpre = subhead;
                temp = curr;  // new start for next group

                // FIX \U0001f511 → keep counterk in sync with temp
                if (!temp) return dummy->next;  
                counterk = temp;  
                count = 0;
                continue; // skip the counterk++ below, we already moved
            }

            counterk = counterk->next;
        }

        return dummy->next;
    }
};
