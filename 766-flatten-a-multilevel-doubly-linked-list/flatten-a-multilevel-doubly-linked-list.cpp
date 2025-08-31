/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        Node* curr = head;
        while(curr != NULL){
            if(curr->child != NULL){
                Node* Next = curr->next;  //at 4 stores four
                curr->next = flatten(curr->child);  //after 3-> moves to down and performs recursion and connects 3->7;
                curr->next->prev = curr; //conects 7 prev to 3
                curr->child = NULL; //and now making 3->child to NULL

            //find tail
            while(curr->next != NULL){
                curr = curr->next;
            }
            //connect tail to Next 4
            if(Next !=  NULL){
                curr->next = Next;
                Next->prev = curr;
            }

            }
           //increment current;
            curr = curr->next;
        }
        return head;
    }
};