// Should return right view of tree
class Solution {
    void findRightView(Node *root, int level, vector<int>& ans){
        if(!root) return;
        if(level==ans.size()) ans.push_back(root->data);
        findRightView(root->right,level+1,ans);
        findRightView(root->left,level+1,ans);
    }
  public:
    // Function to return list containing elements of right view of binary tree.
    vector<int> rightView(Node *root) {
        vector<int> ans;
        findRightView(root,0,ans);
        return ans;
    }
};
