// Time Complexity: O(N log k) where N is the total number of nodes across all lists, and k is the number of lists.
// Space Complexity: O(k) for the min-heap.

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *head=NULL, *tail=NULL;
        priority_queue<pair<int,ListNode*>, vector<pair<int,ListNode*>>, greater<pair<int,ListNode*>>> minheap;
        int k=lists.size();
        if(k==0) return NULL;
        for(int i=0;i<k;i++){
            if(lists[i])
                minheap.push({lists[i]->val,lists[i]});
        }
        while(!minheap.empty()){
            auto top=minheap.top(); minheap.pop();
            if(head==NULL){
                head=tail=top.second;
            }
            else{
                tail->next=top.second;
                tail=top.second;
            }
            if(tail->next) minheap.push({tail->next->val,tail->next});
        }
        return head;
    }
};
