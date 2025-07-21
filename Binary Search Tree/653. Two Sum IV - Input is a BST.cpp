class BSTIterator {
    stack<TreeNode*> myStack;
    bool reverse;
    void pushAll(TreeNode* node){
        while(node){
            myStack.push(node);
            node=reverse?node->right:node->left;
        }
    }
public:
    BSTIterator(TreeNode* root, bool isReverse) {
        reverse=isReverse;
        pushAll(root);
    }
    
    int next() {
        TreeNode* tmpNode=myStack.top();
        myStack.pop();
        if(!reverse) pushAll(tmpNode->right);
        else pushAll(tmpNode->left);
        return tmpNode->val;
    }
    
    bool hasNext() {
        return !myStack.empty();
    }
};

class Solution {

public:
    bool findTarget(TreeNode* root, int k) {
        if(!root) return false;
        BSTIterator l(root,false);
        BSTIterator r(root,true);
        int i=l.next();
        int j=r.next();
        while(i<j){
            if(i+j==k) return true;
            else if(i+j<k) i=l.next();
            else j=r.next();
        }
        return false;
    }
};
