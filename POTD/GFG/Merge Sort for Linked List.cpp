class Solution {
    Node* findMid(Node* head){
        Node *slow=head, *fast=head->next;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    Node* merge(Node* left, Node* right){
        Node* dummy=new Node(-1);
        Node* temp=dummy;
        while(left && right){
            if(left->data<=right->data){
                temp->next=left;
                temp=left;
                left=left->next;
            }
            else{
                temp->next=right;
                temp=right;
                right=right->next;
            }
        }
        if(left) temp->next=left;
        else temp->next=right;
        return dummy->next;
    }
  public:
    Node* mergeSort(Node* head) {
        if(!head || !head->next) return head;
        Node* middle=findMid(head);
        Node* lefthead=head, *righthead=middle->next;
        middle->next=NULL;              // I missed this line :(
        lefthead=mergeSort(lefthead);
        righthead=mergeSort(righthead);
        return merge(lefthead,righthead);
    }
};
