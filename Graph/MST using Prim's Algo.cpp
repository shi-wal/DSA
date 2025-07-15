// TC: O(ElogE), SC:O(V+E)

class Solution {
  public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[]) {
        int cost=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<bool> vis(V,false);
        pq.push({0,0});
        while(!pq.empty()){
            auto top=pq.top(); pq.pop();
            int wt=top.first, node=top.second;
            if(!vis[node]){
                vis[node]=true;
                cost+=wt;
                for(auto it:adj[node]){
                    int adjnode=it[0], edW=it[1];
                    if(!vis[adjnode]) pq.push({edW,adjnode});
                }
            }
        }
        return cost;
    }
};
