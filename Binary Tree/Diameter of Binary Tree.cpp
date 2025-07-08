// TC: O(N)

class Solution {
    int findHeight(TreeNode* root, int& diameter){
        if(!root) return 0;
        int lh=findHeight(root->left,diameter);
        int rh=findHeight(root->right,diameter);
        diameter=max(diameter,lh+rh);
        return 1+max(lh,rh);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter=0;
        findHeight(root,diameter);
        return diameter;
    }
};
