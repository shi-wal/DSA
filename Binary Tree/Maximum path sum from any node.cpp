class Solution {
    int findMaxSum(TreeNode* root, int& maxsum){
        if(!root) return 0;
        int leftsum=max(0,findMaxSum(root->left,maxsum)); // to ignore negative path nodes, we are doing max()
        int rightsum=max(0,findMaxSum(root->right,maxsum));
        maxsum=max(maxsum,root->val+leftsum+rightsum);
        return root->val + max(leftsum, rightsum);
    }
public:
    int maxPathSum(TreeNode* root) {
        int maxsum=INT_MIN;
        findMaxSum(root,maxsum);
        return maxsum;
    }
};
