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
        Node* curr=head;
        while(curr){
            Node* temp=new Node(curr->val);
            temp->next=curr->next;
            curr->next=temp;
            curr=curr->next->next;
        }
        curr=head;
        while(curr){
            Node* temp=curr->next;
            if(curr->random) temp->random=curr->random->next;
            else temp->random=NULL;
            curr=curr->next->next;
        }
        curr=head;
        Node* newHead=curr?curr->next:NULL;
        Node* prev=NULL;
        while(curr){
            Node* temp=curr->next;
            curr->next=temp->next;
            curr=curr->next;
            if(prev) prev->next=temp;
            prev=temp;
        }
        return newHead;
    }
};
