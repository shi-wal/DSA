class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        int width=0;
        queue<pair<TreeNode*,unsigned long long>> q; //{node,index}
        q.push({root,0});
        while(!q.empty()){
            int size=q.size();
            unsigned long long imin=q.front().second;
            int first,last;
            for(int i=0;i<size;i++){
                unsigned long long curr_id=q.front().second-imin;
                TreeNode* node=q.front().first; 
                q.pop();
                if(i==0) first=curr_id;
                if(i==size-1) last=curr_id;
                if(node->left) q.push({node->left,curr_id*2+1});
                if(node->right) q.push({node->right,curr_id*2+2});
            }
            width=max(width,last-first+1); 
        }
        return width;
    }
};
