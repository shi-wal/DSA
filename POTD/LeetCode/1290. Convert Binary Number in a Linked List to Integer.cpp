// optimized

class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int value=0;
        while(head){
            value=(value<<1) | head->val;
            head=head->next;
        }
        return value;
    }
};


// my code

class Solution {
public:
    int getDecimalValue(ListNode* head) {
        ListNode* curr=head;
        int len=0;
        while(curr->next){
            curr=curr->next;
            len++;
        }
        int value=0;
        curr=head;
        while(curr){
            if(curr->val==1)
                value+=pow(2,len);
            len--;
            curr=curr->next;
        }
        return value;
    }
};
