class NodeValue{
    public:
    int maxNode, minNode, maxSum;
    NodeValue(int maxi, int mini, int sum){
        maxNode=maxi;
        minNode=mini;
        maxSum=sum;
    }
};
class Solution {
    int maxSum=0;
    NodeValue largestBstHelper(TreeNode *root){
        if(!root) return NodeValue(INT_MIN,INT_MAX,0);
        auto leftS=largestBstHelper(root->left);
        auto rightS=largestBstHelper(root->right);
        if(leftS.maxNode < root->val && root->val < rightS.minNode){
            // It is a BST
            int currSum=leftS.maxSum+rightS.maxSum+root->val;
            maxSum=max(maxSum,currSum);
            return NodeValue(max(root->val,rightS.maxNode),
                min(root->val,leftS.minNode),currSum);
        }
        return NodeValue(INT_MAX,INT_MIN, max(leftS.maxSum,rightS.maxSum));
    }
public:
    int maxSumBST(TreeNode* root) {
        int ans=largestBstHelper(root).maxSum;
        return maxSum;
    }
};
