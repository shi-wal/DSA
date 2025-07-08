class Solution {
  public:
    // Function to return a list of nodes visible from the top view
    // from left to right in Binary Tree.
    vector<int> topView(Node *root) {
        vector<int> ans;
        if(!root) return ans;
        map<int,int> level;
        queue<pair<Node*,int>> q;
        q.push({root,0});
        while(!q.empty()){
            auto item=q.front(); q.pop();
            Node* node=item.first;
            int vertical=item.second;
            if(level.find(vertical)==level.end()) level[vertical]=node->data;
            if(node->left) q.push({node->left,vertical-1});
            if(node->right) q.push({node->right,vertical+1});
        }
        for(auto item:level)
            ans.push_back(item.second);
        return ans;
    }
};
