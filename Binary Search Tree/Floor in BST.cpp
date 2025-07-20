// Function to search a node in BST.
class Solution {
  public:
    int floor(Node* root, int x) {
        int ans=-1;
        while(root){
            int curr=root->data;
            if(curr==x) return curr;
            else if(curr<x) {
                ans=curr;
                root=root->right;
            }
            else root=root->left;
        }
        return ans;
    }
};
