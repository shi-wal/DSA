class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL || root==p || root==q) return root;
        TreeNode* leftS=lowestCommonAncestor(root->left,p,q);
        TreeNode* rightS=lowestCommonAncestor(root->right,p,q);
        if(leftS==NULL) return rightS;
        else if(rightS==NULL) return leftS;
        else return root;
    }
};
