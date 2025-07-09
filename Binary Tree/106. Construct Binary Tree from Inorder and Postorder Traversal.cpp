class Solution {
    TreeNode* build(vector<int>& postorder, int poststart, int postend,
        vector<int>& inorder, int instart, int inend, unordered_map<int,int>& mp){
            if(poststart>postend || instart>inend) return NULL;
            TreeNode* root=new TreeNode(postorder[postend]);
            int inroot=mp[root->val];
            int numsLeft=inroot-instart;
            root->left=build(postorder,poststart,poststart+numsLeft-1, inorder, instart, inroot-1,mp);
            root->right=build(postorder,poststart+numsLeft,postend-1, inorder, inroot+1, inend, mp);
            return root;
        }

public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int> mp;
        int n=inorder.size();
        for(int i=0;i<n;i++)   mp[inorder[i]]=i;
        return build(postorder, 0, n-1, 
                    inorder, 0, n-1, mp);

    }
};
