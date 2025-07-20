/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    void inorder(TreeNode* root, int k, int& cnt, int& ans){
        if(!root || cnt>k) return;
        inorder(root->left,k,cnt,ans);
        cnt++;
        if(cnt==k) {
            ans=root->val;
            return;
        }
        inorder(root->right,k,cnt,ans);
    }

public:
    int kthSmallest(TreeNode* root, int k) {
        int ans=INT_MIN;
        int cnt=0;
        inorder(root,k,cnt,ans);
        return ans;
    }
};
