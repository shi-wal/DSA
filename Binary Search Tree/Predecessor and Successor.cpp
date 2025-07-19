class Solution {
    Node* findSuc(Node* root, int key){
        Node* successor=NULL;
        while(root){
            if(root->data<=key) root=root->right;
            else{
                successor=root;
                root=root->left;
            }
        }
        return successor;
    }
    Node* findPre(Node* root, int key){
        Node* predecessor=NULL;
        while(root){
            if(root->data>=key) root=root->left;
            else{
                predecessor=root;
                root=root->right;
            }
        }
        return predecessor;
    }
    
  public:
    vector<Node*> findPreSuc(Node* root, int key) {
        Node* successor=findSuc(root,key);
        Node* predecessor=findPre(root,key);
        return {predecessor,successor};
    }
};
