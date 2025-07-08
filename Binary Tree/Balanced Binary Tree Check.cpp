class Solution {
    int findHeight(TreeNode* root){
        if(!root) return 0;
        int lh=findHeight(root->left);
        int rh=findHeight(root->right);
        if(lh==-1 || rh==-1) return -1; // some subtree is not height-balanced
        if(abs(lh-rh)>1) return -1;
        return 1+max(lh,rh);
    }
public:
    bool isBalanced(TreeNode* root) {
        return findHeight(root)!=-1;
    }
};
