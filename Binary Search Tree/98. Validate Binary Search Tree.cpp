// TC: O(n)
class Solution {
    bool validate(TreeNode* root, long leftRange, long rightRange){
        if(!root) return true;
        if(root->val<=leftRange || root->val>=rightRange) return false;
        return validate(root->left,leftRange,root->val) && validate(root->right,root->val,rightRange);
    }
public:
    bool isValidBST(TreeNode* root) {
        return validate(root,LONG_MIN,LONG_MAX);
    }
};
