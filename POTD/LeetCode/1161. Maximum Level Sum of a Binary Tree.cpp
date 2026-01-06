class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        int ans=0, maxSum=INT_MIN;
        queue<pair<TreeNode*,int>> q;
        q.push({root,1});
        while(!q.empty()){
            int size=q.size();
            int sum=0;
            int level=q.front().second;
            for(int i=0;i<size;i++){
                TreeNode* node=q.front().first;
                q.pop();
                sum+=node->val;
                if(node->left) q.push({node->left,level+1});
                if(node->right) q.push({node->right,level+1}); 
            }
            if(maxSum<sum){
                maxSum=sum;
                ans=level;
            }
        }
        return ans;
    }
};
