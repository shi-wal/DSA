/*Linked list Node structure

struct Node
{
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};
*/

class Solution {
  public:
    Node* mergeKLists(vector<Node*>& arr) {
        vector<int> values;
        for(Node* head:arr){
            while(head){
               values.push_back(head->data);
               head=head->next;
            }
        }
        sort(values.begin(),values.end());
        int n=values.size();
        Node* head=new Node(values[0]);
        Node* curr=head;
        for(int i=1;i<n;i++){
            curr->next=new Node(values[i]);
            curr=curr->next;
        }
        return head;
    }
};
