// O(N log K)
// N = number of nodes
// K = number of vertical columns (in worst case, K ≈ N)
// log K from map insertions

class Solution {
  public:
    vector<int> bottomView(Node *root) {
        vector<int> ans;
        if(!root) return ans;
        queue<pair<Node*,int>> q; // {node,vertical level}
        map<int,int> mp;
        q.push({root,0});
        while(!q.empty()){
            auto item=q.front(); q.pop();
            Node* node=item.first;
            int vertical=item.second;
            mp[vertical]=node->data;
            if(node->left) q.push({node->left,vertical-1});
            if(node->right) q.push({node->right,vertical+1});
        }
        for(auto item:mp){
            ans.push_back(item.second);
        }
        return ans;
    }
};
