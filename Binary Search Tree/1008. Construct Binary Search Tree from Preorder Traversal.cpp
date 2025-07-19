// TC: O(n)

class Solution {
    TreeNode* makeBST(vector<int>& preorder, int& i, int n, int bound){
        if(i==n || preorder[i]>=bound) return NULL;
        TreeNode* root=new TreeNode(preorder[i++]); 
        root->left=makeBST(preorder,i,n,root->val);
        root->right=makeBST(preorder,i,n,bound);
        return root;
    }

public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i=0, n=preorder.size();
        return makeBST(preorder,i,n,INT_MAX);
    }
};
