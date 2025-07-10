class Solution {
    void doDFS(vector<vector<int>>& adj, int node, vector<bool>& vis, 
        vector<int>& ans){
            vis[node]=true;
            ans.push_back(node);
            for(auto it: adj[node]){
                if(!vis[it]) doDFS(adj,it,vis,ans);
            }
        }
  public:
    vector<int> dfs(vector<vector<int>>& adj) {
        int n=adj.size();
        vector<bool> vis(n,false);
        vector<int> ans;
        doDFS(adj,0 ,vis, ans);
        return ans;
    }
};
