/*You are given a doubly linked list which in addition to the next and previous pointers, it could have a child pointer, which may or may not point to a separate doubly linked list. These child lists may have one or more children of their own, and so on, to produce a multilevel data structure, as shown in the example below.

Flatten the list so that all the nodes appear in a single-level, doubly linked list. You are given the head of the first level of the list.*/


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
        if(head == NULL)
            return head;
        stack <Node*> s;
        Node* cur = head;
        while(cur != NULL) {
            if(cur->child != NULL){
                if(cur->next != NULL) {
                    s.push(cur->next);
                }
                cur->next = cur->child;
                if(cur->next != NULL) {
                    cur->next->prev = cur;
                }
                cur->child = NULL;
            }
            else if(cur->next == NULL && ! s.empty()) {
                cur->next = s.top();
                s.pop();
                if(cur->next != NULL)
                cur->next->prev = cur;
            }
            cur = cur->next;
        }
        return head;
               
    }
}; 