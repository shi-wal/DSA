class Solution {
  public:
    vector<vector<int>> levelOrder(Node *root) {
        vector<vector<int>> bfs;
        if(!root) return bfs;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            int size=q.size();
            vector<int> level;
            for(int i=0;i<size;i++){
                Node* node=q.front();
                q.pop();
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
                level.push_back(node->data);
            }
            bfs.push_back(level);
        }
        return bfs;
    }
};
