class Solution {
  public:
    Node* segregate(Node* head) {
        Node* zero=NULL, *zerocurr=NULL;
        Node* one=NULL, *onecurr=NULL;
        Node* two=NULL, *twocurr=NULL;
        while(head){
            Node* temp=head->next;
            if(head->data==0){
                if(zero==NULL) {
                    zero=head;
                    zerocurr=zero;
                }
                else {
                    zerocurr->next=head;
                    zerocurr=zerocurr->next;
                }
                zerocurr->next=NULL;
            }
            else if(head->data==1){
                if(one==NULL) {
                    one=head;
                    onecurr=one;
                }
                else {
                    onecurr->next=head;
                    onecurr=onecurr->next;
                }
                onecurr->next=NULL;
            }
            else{
                if(two==NULL) {
                    two=head;
                    twocurr=two;
                }
                else {
                    twocurr->next=head;
                    twocurr=twocurr->next;
                }
                twocurr->next=NULL;
            }
            head=temp;
        }
        if(zero) {
            zerocurr->next=one;
            if(!one) zerocurr->next=two;
        }
        if(one) onecurr->next=two;
        return zero?zero:one?one:two;
    }
};
