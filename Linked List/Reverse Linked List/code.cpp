class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* curr=NULL;
        while(head!=NULL){
            ListNode* temp=head->next;
            head->next=curr;            
            curr=head;
            head=temp;
        }
        return curr;
    }
};
