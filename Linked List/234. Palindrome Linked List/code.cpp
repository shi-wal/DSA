/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
    ListNode *reverseList(ListNode* head){
        ListNode* newhead=NULL;
        while(head){
            ListNode* temp=head->next;
            head->next=newhead;
            newhead=head;
            head=temp;
        }
        return newhead;
    }
public:
    bool isPalindrome(ListNode* head) {
        if(!head || !head->next) return true;
        ListNode *slow=head, *fast=head;
        while(fast->next && fast->next->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        slow->next=reverseList(slow->next);
        slow=slow->next;
        while(slow){
            if(head->val != slow->val) return false;
            slow=slow->next;
            head=head->next;
        }
        return true;
    }
};
