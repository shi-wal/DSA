class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inorder;
        TreeNode* curr=root;
        while(curr){
            // case 1 : left child absent: means we have reached leftmost child
            if(curr->left==NULL){
                inorder.push_back(curr->val);
                curr=curr->right;
            }
            else{
                TreeNode* prev=curr->left;
                // checking that thread is not connected.
                while(prev->right && prev->right!=curr){
                    prev=prev->right;
                }
                // case 2 : connecting thread of rightmost grand-child of left child with itself(parent of left child)
                if(prev->right==NULL){
                    prev->right=curr;
                    curr=curr->left;
                }
                // case 3 : thread is already connected
                else{
                    prev->right=NULL;
                    // this is being added root node, after checking & adding left node.
                    inorder.push_back(curr->val);
                    curr=curr->right;
                }
            }
        }
        return inorder;
    }
};
