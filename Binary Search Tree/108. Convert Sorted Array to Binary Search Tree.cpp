class Solution {
    TreeNode* getBST(vector<int>& nums, int start, int end){
        if(start>end) return NULL;
        int mid=(start+end)/2;
        TreeNode* root=new TreeNode(nums[mid]);
        root->left=getBST(nums,start,mid-1);
        root->right=getBST(nums,mid+1,end);
        return root;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return getBST(nums,0,nums.size()-1);
    }
};
