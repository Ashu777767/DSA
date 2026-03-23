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
struct cmp{
    bool operator()(ListNode* a,ListNode* b){
        return a->val>b->val;
    }
};
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        int k = lists.size();
        priority_queue<ListNode*,vector<ListNode*>,cmp>minHeap;
        for(int i = 0;i<k;i++){
            if(lists[i]!= NULL)
        minHeap.push(lists[i]);
        }
         
        ListNode* dummy = new ListNode(0);
        ListNode* head = dummy;
        while(!minHeap.empty()){
            ListNode* temp =minHeap.top();
            minHeap.pop();
            if(temp!=NULL && temp->next){
                minHeap.push(temp->next);
            }
            dummy->next = temp;
            dummy = dummy->next;
        }
        return head->next;
    }
};