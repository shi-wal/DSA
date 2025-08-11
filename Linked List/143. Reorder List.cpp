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
public:
    void reorderList(ListNode* head) {
        ListNode* slow=head, *fast=head;
        while(fast && fast->next){
            fast=fast->next->next;
            slow=slow->next;
        }
        ListNode* second=slow->next, *prev=NULL;
        slow->next=NULL;
        while(second){
            ListNode* temp=second->next;
            second->next=prev;
            prev=second;
            second=temp;
        }
        ListNode* first=head;
        second=prev;

        while(second){
            ListNode* temp1=first->next;
            ListNode* temp2=second->next;
            first->next=second;
            second->next=temp1;
            second=temp2;
            first=temp1;
        }
        return;
    }
};
