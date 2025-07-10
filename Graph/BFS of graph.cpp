class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfs(vector<vector<int>> &adj) {
        int n=adj.size();
        vector<bool> vis(n,false);
        vector<int> ans;
        queue<int> q;
        q.push(0);
        vis[0]=true;
        while(!q.empty()){
            int node=q.front(); q.pop();
            ans.push_back(node);
            for(int x:adj[node]){
                if(!vis[x]) {
                    q.push(x);
                    vis[x]=true;
                }
            }
        }
        return ans;
    }
};
