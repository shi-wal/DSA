// do reverse in-order to find kth largest
class Solution {
    void reverse_inorder(Node *root, int k, int& ans, int& cnt){
        if(!root || cnt>k) return;
        reverse_inorder(root->right,k,ans,cnt);
        cnt++;
        if(cnt==k){
            ans=root->data; return;
        }
        reverse_inorder(root->left,k,ans,cnt);
    }
    
  public:
    int kthLargest(Node *root, int k) {
        int ans=INT_MAX;
        int cnt=0;
        reverse_inorder(root,k, ans,cnt);
        return ans;
    }
};
