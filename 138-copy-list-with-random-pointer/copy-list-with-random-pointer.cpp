/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL) return NULL;
        unordered_map<Node*,Node*>map;
        Node* newHead = new Node(head->val);  //create a copy of first node
        Node* oldptr = head->next;
        Node* newptr = newHead;
        map[head] = newptr;
        while(oldptr != NULL){
            Node* copy = new Node(oldptr->val); //creats a copy and merge with newptr to point to  copy not to original
            map[oldptr] = copy; //stores the original and copy node as key:valu
            newptr->next = copy;
            newptr = newptr->next;
            oldptr = oldptr->next;
        }
        oldptr = head;
        newptr = newHead;
        while(oldptr != NULL){
            newptr->random = map[oldptr->random];//by checking original random link provides the copy of original node where the newptr should merge using the val of key from original node
            oldptr = oldptr->next;
            newptr = newptr->next;
        }

        return newHead;
    }
};