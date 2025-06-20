//TC: O(1)
// Done myself in single run!
class Solution {
public:
    void deleteNode(ListNode* node) {
        int data=node->next->val;
        node->val=data;
        ListNode* temp=node->next->next;
        delete(node->next);
        node->next=temp;
    }
};
