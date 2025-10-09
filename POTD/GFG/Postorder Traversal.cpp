class Solution {
    void doPostorder(Node* root, vector<int>& res){
        if(root){
           doPostorder(root->left,res);
           doPostorder(root->right,res);
           res.push_back(root->data);
        }
    }
  public:
    vector<int> postOrder(Node* root) {
        vector<int> res;
        doPostorder(root,res);
        return res;
    }
};
