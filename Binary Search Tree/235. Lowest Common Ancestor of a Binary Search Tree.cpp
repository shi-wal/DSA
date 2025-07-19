// TC: O(H) , H= height of BST

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while(root){
            if(root->val > max(q->val,p->val)) root=root->left; // both p & q lies in left subtree
            else if(root->val < min(p->val,q->val)) root=root->right; // // both p & q lies in right subtree
            else return root;  // either p & q lies not in same subtree or any one (p or q)->val==root->val 
        }
        return NULL;
    }
};
