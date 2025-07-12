// TC: O(V+E)

class Solution {
    void dfs(int node, vector<bool>& vis, stack<int>& st, vector<vector<int>>& adj){
        vis[node]=true;
        for(int neighbour:adj[node]){
            if(!vis[neighbour]){
                dfs(neighbour,vis,st,adj);
            }
        }
        st.push(node);
    }
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        vector<bool> vis(V,false);
        stack<int> st;
        vector<vector<int>> adj(V);
        for(auto edge:edges){
            adj[edge[0]].push_back(edge[1]);
        }
        for(int i=0;i<V;i++){
            if(!vis[i]) dfs(i,vis,st, adj);
        }
        vector<int> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};
