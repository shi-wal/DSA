class Solution {
  public:
    // Function to check whether all nodes of a tree have the value
    // equal to the sum of their child nodes.
    int isSumProperty(Node *root) {
        if(!root || (!root->left && !root->right)) return 1;
        int left=root->left?root->left->data:0;
        int right=root->right?root->right->data:0;
        if(root->data != left+right) return 0;
        return isSumProperty(root->left) && isSumProperty(root->right);
    }
};
