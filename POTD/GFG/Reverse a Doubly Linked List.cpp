/*
class Node {
  public:
    int data;
    Node *next;
    Node *prev;
    Node(int val) {
        data = val;
        next = NULL;
        prev = NULL;
    }
};

*/
class Solution {
  public:
    Node *reverse(Node *head) {
        Node *newHead=head;
        while(head){
            Node *further=head->next;
            head->next=head->prev;
            head->prev=further;
            newHead=head;
            head=further;
        }
        return newHead;
    }
};
