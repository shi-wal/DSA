class Solution {
    int val;
    void update(Node *root){
        if(!root) return;
        update(root->right);
        int newVal=val+root->data;
        root->data=val;
        val=newVal;
        update(root->left);
    }
  public:
    void transformTree(Node *root) {
        val=0;
        update(root);
    }
};
