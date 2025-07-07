// GFG
class Solution {
  public:
    vector<vector<int>> verticalOrder(Node *root) {
        vector<vector<int>> ans;
        if (!root) return ans;
        // vertical -> list of values (in level order)
        map<int, vector<int>> nodes;
        // queue stores {node, vertical}
        queue<pair<Node*, int>> todo;
        todo.push({root, 0});

        while(!todo.empty()){
            auto p=todo.front();
            todo.pop();
            Node* node=p.first;
            int x=p.second;
            nodes[x].push_back(node->data);
            if(node->left) todo.push({node->left,x-1});
            if(node->right) todo.push({node->right,x+1});
        }
        
        for(auto values : nodes){
            ans.push_back(values.second);
        }
        return ans;
    }
};


// LeetCode
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        if (!root) return ans;
        map<int,map<int,multiset<int>>> nodes; // in LeetCode they are asking for sort nodes by their values if multiple nodes in same row & column.
        queue<pair<TreeNode*,pair<int,int>>> todo; // {node,{vertical level,Depth level}}
        todo.push({root,{0,0}});
        while(!todo.empty()){
            auto p=todo.front();
            todo.pop();
            TreeNode* node=p.first;
            int x=p.second.first, y=p.second.second;
            nodes[x][y].insert(node->val);
            if(node->left) todo.push({node->left,{x-1,y+1}});
            if(node->right) todo.push({node->right,{x+1,y+1}});
        }
        for(auto p:nodes){
            vector<int> col;
            for(auto q:p.second){
                col.insert(col.end(),q.second.begin(),q.second.end());
            }
            ans.push_back(col);
        }
        return ans;
    }
};
