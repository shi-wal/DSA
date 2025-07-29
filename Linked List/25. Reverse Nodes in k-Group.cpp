class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head || k==1) return head;
        ListNode* dummy=new ListNode(0);
        dummy->next=head;
        ListNode *curr=dummy, *pre=dummy, *nex=dummy;
        int cnt=0;
        while(curr->next){
            curr=curr->next;
            cnt++;
        }
        while(cnt>=k){
            curr=pre->next;
            nex=curr->next;
            for(int i=1;i<k;i++){ // for k-1 links to reverse
                curr->next=nex->next; // curr->next->next
                nex->next=pre->next; // curr
                pre->next=nex;
                nex=curr->next;
            }
            pre=curr;
            cnt-=k;
        }
        return dummy->next;
    }
};
