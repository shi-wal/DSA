class Solution {
    void findSum(Node* root, int l, int r, int& sum){
        if(!root) return;
        if(root->data>=l && root->data<=r) sum+=root->data;
        findSum(root->left,l,r,sum);
        findSum(root->right,l,r,sum);
    }
  public:
    int nodeSum(Node* root, int l, int r) {
        if(!root) return 0;
        int sum=0;
        findSum(root,l,r,sum);
        return sum;
    }
};
