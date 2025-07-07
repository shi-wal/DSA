// TC: O(N), SC: O(height of tree)

class Solution {
    void findleftView(Node *root, int level, vector<int>& ans){
        if(!root) return;
        if(level==ans.size()) ans.push_back(root->data);
        findleftView(root->left,level+1,ans);
        findleftView(root->right,level+1,ans);
    }
    
  public:
    vector<int> leftView(Node *root) {
        vector<int> ans;
        findleftView(root,0,ans);
        return ans;
    }
};
