class Solution {
    bool symmetricCheck(TreeNode* ls, TreeNode* rs){
        if(!ls || !rs) return ls==rs;
        if(ls->val!=rs->val) return false;
        return symmetricCheck(ls->left,rs->right) && symmetricCheck(ls->right,rs->left);
    }
public:
    bool isSymmetric(TreeNode* root) {
        return !root || symmetricCheck(root->left,root->right);
    }
};
