/* struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};  */

int findCeil(Node* root, int input) {
    int ceil=-1;
    while(root){
        int curr=root->data;
        if(curr==input) return curr;
        else if(curr>input) {
            ceil=curr;
            root=root->left;
        }
        else root=root->right;
    }
    return ceil;
}
