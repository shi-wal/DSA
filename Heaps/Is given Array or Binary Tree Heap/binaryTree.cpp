class Solution {
    int countNode(Node* tree){
        if(!tree) return 0;
        int ans=1+countNode(tree->left)+countNode(tree->right);
        return ans;
    }
    bool isCBT(Node* tree, int index, int count){
        if(!tree) return true;
        if(index>=count) return false;
        return isCBT(tree->left, 2*index+1, count) && isCBT(tree->right, 2*index+2, count);
    }
    bool isMaxOrder(Node* tree){
        if(!tree->left && !tree->right) return true; //leaf node
        if(!tree->right) return tree->data >= tree->left->data; //only left child exist
        bool leftPart=isMaxOrder(tree->left);
        bool rightPart=isMaxOrder(tree->right);
        return leftPart && rightPart && tree->data >= tree->left->data && 
            tree->data >= tree->right->data;
    }
  public:
    bool isHeap(Node* tree) {
        int index=0;
        int totalCount=countNode(tree);
        if(isCBT(tree,index,totalCount) && isMaxOrder(tree))
            return true;
        return false;
    }
};
