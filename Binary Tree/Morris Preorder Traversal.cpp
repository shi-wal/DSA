// TC: O(N), SC: O(1)

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> preorder;
        TreeNode* curr=root;
        while(curr){
            if(!curr->left){
                preorder.push_back(curr->val);
                curr=curr->right;
            }
            else{
                TreeNode* prev=curr->left;
                while(prev->right && prev->right!=curr) prev=prev->right;
                if(!prev->right){
                    prev->right=curr;
                    preorder.push_back(curr->val); // only this line is shifted from below else block to here (only difference b/w morris inorder & preorder)
                    curr=curr->left;
                }
                else{
                    prev->right=NULL;
                    curr=curr->right;
                }
            }
        }
        return preorder;
    }
};
