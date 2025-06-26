class Solution {
    bool isSafe(int node, int v, vector<vector<int>> &adj, vector<int>& color, int clr){
        for(auto k: adj[node]){
            if(color[k]==clr) return false;
        }
        return true;
    }
    
    bool solve(int node, int v, vector<vector<int>> &adj, vector<int>& color, int m){
        if(node==v) return true;
        for(int i=1;i<=m;i++){
            if(isSafe(node,v,adj,color,i)) {
                color[node]=i;
                if(solve(node+1,v,adj,color,m))  return true;
                color[node]=0; //backtrack
            }
        }
        return false;
    }
    
  public:
    bool graphColoring(int v, vector<vector<int>> &edges, int m) {
        vector<vector<int>> adj(v);
        for(auto edge:edges){
           adj[edge[0]].push_back(edge[1]);
           adj[edge[1]].push_back(edge[0]);
        }
        vector<int> color(v,0);
        if(solve(0,v,adj,color,m)) return true;
        return false;
    }
};
