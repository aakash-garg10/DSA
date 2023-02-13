// https://leetcode.com/problems/copy-list-with-random-pointer/
// TUTORIAL ==>https://takeuforward.org/data-structure/clone-linked-list-with-random-and-next-pointer/

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
        if(head==nullptr)   return nullptr;
        Node* cur=head;
        Node* temp;
 // we will create each node and link it next to the original nodes. This contributes to step1
        while(cur){
            temp=cur->next;
            cur->next=new Node(cur->val);
            cur->next->next=temp;
            cur=temp;
        }
// In step 2 we create random pointer links among deep copy nodes.
        cur=head;
        while(cur){
            cur->next->random=cur->random ? cur->random->next : cur->random;
            cur=cur->next->next;
        }
// differentiate the original list and deep copy one.
        Node* original=head;
        Node* copy=head->next;
        temp=copy;
        while(original and copy){
            original->next=original->next->next;
            copy->next=copy->next ? copy->next->next : copy->next;
            original=original->next;
            copy=copy->next;
        }
        return temp;
    }
};