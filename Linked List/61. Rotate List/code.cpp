class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode *tail=head;
        if(k==0 || !head || !head->next) return head;
        int len=1;
        while(tail->next){
            len++;
            tail=tail->next;
        }
        k=k%len;
        if(k==0) return head;        
        tail->next=head;
        int count=len-k;
        for(int i=1;i<count;i++){
            head=head->next;
        }
        ListNode *newHead=head->next;
        head->next=NULL;
        return newHead;
    }
};
