class NodeValue{
    public:
    int maxNode, minNode, maxSize;
    NodeValue(int maxi, int mini, int size){
        maxNode=maxi;
        minNode=mini;
        maxSize=size;
    }
};
class Solution {
    NodeValue largestBstHelper(Node *root){
        if(!root) return NodeValue(INT_MIN,INT_MAX,0);
        auto leftS=largestBstHelper(root->left);
        auto rightS=largestBstHelper(root->right);
        if(leftS.maxNode < root->data && root->data < rightS.minNode){
            // It is a BST
            return NodeValue(max(root->data,rightS.maxNode),
                min(root->data,leftS.minNode), leftS.maxSize+rightS.maxSize+1);
        }
        return NodeValue(INT_MAX,INT_MIN, max(leftS.maxSize,rightS.maxSize));
    }
  public:
    // Return the size of the largest sub-tree which is also a BST
    int largestBst(Node *root) {
        return largestBstHelper(root).maxSize;
    }
};
