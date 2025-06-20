class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA || !headB) return NULL;
        ListNode *a=headA, *b=headB;
        // if no intersection is there still after 2nd iteration, both will point to NULL at same time
        while(a!=b){
            a= a==NULL ?headB:a->next; 
            b= b==NULL ?headA:b->next;
        }
        return a;
    }
};
