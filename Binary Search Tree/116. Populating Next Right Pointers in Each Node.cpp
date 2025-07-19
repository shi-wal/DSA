// Method 1

class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return NULL;
        Node* leftMost=root;
        while(leftMost->left){
            Node* curr=leftMost; // root
            leftMost=leftMost->left; //left child of leftMost
            while(curr){
                curr->left->next=curr->right;
                if(curr->next) curr->right->next=curr->next->left;
                curr=curr->next;
            }
        }
        return root;
    }
};


// Method 2

class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return nullptr;
        queue<Node*> q;
        q.push(root);        
        while(size(q)) {
            Node* rightNode = nullptr;               // set rightNode to null initially
            for(int i = size(q); i; i--) {           // traversing each level
                auto cur = q.front(); q.pop();       // pop a node from current level and,
                cur -> next = rightNode;             // set its next pointer to rightNode
                rightNode = cur;                     // update rightNode as cur for next iteration
                if(cur -> right)                     // if a child exists
                    q.push(cur -> right),            // IMP: push right first to do right-to-left BFS
                    q.push(cur -> left);             // then push left
            }
        }
        return root;
    }
};
