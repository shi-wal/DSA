// By DFS
class Solution {
    bool checkcycle(vector<vector<int>> &adj, int node, vector<bool> &vis, vector<bool> &dfsVis){
        vis[node]=true;
        dfsVis[node]=true;
        for(auto neigh:adj[node]){
            if(!vis[neigh]){
                if(checkcycle(adj,neigh,vis,dfsVis)) return true;
            }
            else if(dfsVis[neigh]) return true;
        }
        dfsVis[node]=false;
        return false;
    }
  public:
    bool isCyclic(int V, vector<vector<int>> &edges) {
        vector<bool> vis(V,false), dfsVis(V,false);
        vector<vector<int>> adj(V);
        for(auto edge:edges){
            adj[edge[0]].push_back(edge[1]);
        }
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(checkcycle(adj,i,vis,dfsVis)) return true;
            }
        }
        return false;
    }
};
