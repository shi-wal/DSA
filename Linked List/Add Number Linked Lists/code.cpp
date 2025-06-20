class Solution {
    Node* reverse(Node* head){
        Node* newHead=NULL;
        while(head){
            Node* curr=head->next;
            head->next=newHead;
            newHead=head;
            head=curr;
        }
        return newHead;
    }
  public:
    Node* addTwoLists(Node* l1, Node* l2) {
        l1=reverse(l1);
        l2=reverse(l2);
        int carry=0;
        Node *dummy=new Node(-1);
        Node *temp=dummy;
        while(l1 || l2 || carry){
            int sum=carry;
            if(l1){
                sum+=l1->data;
                l1=l1->next;
            }
            if(l2){
                sum+=l2->data;
                l2=l2->next;
            }
            carry=sum/10;
            if(l1==NULL && l2==NULL && sum==0 && carry==0){
                break;
            }
            Node *node=new Node(sum%10);
            temp->next=node;
            temp=temp->next;
        }
        return reverse(dummy->next);
    }
};
