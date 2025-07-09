class Solution {
    TreeNode* build(vector<int>& preorder, int prestart, int preend,
        vector<int>& inorder, int instart, int inend, unordered_map<int,int>& mp){
            if(prestart>preend || instart>inend) return NULL;
            TreeNode* root=new TreeNode(preorder[prestart]);
            int inroot=mp[root->val];
            int numsLeft=inroot-instart;
            root->left=build(preorder,prestart+1,prestart+numsLeft, inorder, instart, inroot-1,mp);
            root->right=build(preorder,prestart+numsLeft+1,preend, inorder, inroot+1, inend,mp);
            return root;
        }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> mp;
        int n=inorder.size();
        for(int i=0;i<n;i++)   mp[inorder[i]]=i;
        return build(preorder, 0, n-1, 
                    inorder, 0, n-1, mp);
    }
};
