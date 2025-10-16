// Given the root of a Binary Search Tree (BST) and two integers l and r, remove all the nodes whose values lie outside the range [l, r].

class Solution {
  public:
    Node* removekeys(Node* root, int l, int r) {
        if(!root) return NULL;
        if(root->data<l) return removekeys(root->right,l,r);
        if(root->data>r) return removekeys(root->left,l,r);
        root->right=removekeys(root->right,l,r);
        root->left=removekeys(root->left,l,r);
        return root;
    }
};
