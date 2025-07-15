// TC: O(V*E)

class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        vector<int> dist(V,1e8);
        dist[src]=0;
        vector<vector<pair<int,int>>> adj(V);
        for(int i=0;i<V-1;i++){
            for(auto edge:edges){
                int u=edge[0], v=edge[1], wt=edge[2];
                if(dist[u]!=1e8 && dist[u]+wt<dist[v]) dist[v]=dist[u]+wt; // dist[u]!=1e8 is done to check if u distance updated earlier 
              // or not, if we update dist[v] when wt=-ve & dist[u]=1e8, then it will not pass test cases.
            }
        }
        // Nth time relaxation
        for(auto edge:edges){
            int u=edge[0], v=edge[1], wt=edge[2];
            if(dist[u]!=1e8 && dist[u]+wt<dist[v]) return {-1};
        }
        return dist;
    }
};
