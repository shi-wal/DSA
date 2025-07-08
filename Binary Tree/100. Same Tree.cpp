// Time Complexity: O(n)
// Where n is the number of nodes in the trees (worst case: both trees are identical and fully traversed).
// Space Complexity: O(h)
// Where h is the height of the tree due to the recursion stack (worst case O(n) for skewed trees, O(log n) for balanced trees).

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q) return true;
        if((p && !q) || (q && !p)) return false;
        if(p && q && p->val!=q->val) return false;

        return isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
    }
};


// Minor cleaner version
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p || !q) return p == q;
        return (p->val == q->val) &&
               isSameTree(p->left, q->left) &&
               isSameTree(p->right, q->right);
    }
};
