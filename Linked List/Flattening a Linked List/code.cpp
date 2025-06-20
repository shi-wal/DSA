// Notes are in diary
class Solution {
    Node* mergeTwoLists(Node *a, Node *b){
        Node *temp=new Node(0);
        Node *res=temp;
        while(a!=NULL && b!=NULL){
            if(a->data < b->data){
                temp->bottom=a;
                a=a->bottom;
            }
            else{
                temp->bottom=b;
                b=b->bottom;
            }
            temp=temp->bottom;
        }
        if(a) temp->bottom=a;
        else temp->bottom=b;
        return res->bottom;
    }
  public:
    // Function which returns the  root of the flattened linked list.
    Node *flatten(Node *root) {
        if(!root || !root->next) return root;
        root->next=flatten(root->next);
        root=mergeTwoLists(root, root->next);
        return root;
    }
};
