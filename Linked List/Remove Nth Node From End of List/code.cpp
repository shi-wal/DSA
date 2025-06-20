class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy=new ListNode();
        dummy->next=head;
        ListNode *slow=dummy, *fast=dummy;
        for(int i=0;i<n;i++) fast=fast->next;
        while(fast->next){
            slow=slow->next;
            fast=fast->next;
        }
        ListNode *del=slow->next;
        slow->next=slow->next->next;
        delete(del);
        return dummy->next;
    }
};
