// notes in diary

class Solution {
    void inorder(Node* root, vector<int>& vals){
        if(!root) return;
        inorder(root->left,vals);
        vals.push_back(root->data);
        inorder(root->right,vals);
    }
    void convertToMaxHeap(Node* root, vector<int>& vals){
        if(!root) return;
        root->data=vals.back();
        vals.pop_back();
        convertToMaxHeap(root->right,vals);
        convertToMaxHeap(root->left,vals);
    }
  public:
    void convertToMaxHeapUtil(Node* root) {
        vector<int> vals;
        inorder(root, vals);
        convertToMaxHeap(root, vals);
    }
};
