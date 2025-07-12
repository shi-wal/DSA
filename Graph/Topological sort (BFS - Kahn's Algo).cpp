// TC: O(V+E)
  
class Solution {
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        vector<int> indegree(V,0);
        queue<int> q;
        vector<vector<int>> adj(V);
        for(auto edge:edges){
            adj[edge[0]].push_back(edge[1]);
            indegree[edge[1]]++;
        }
        for(int i=0;i<V;i++){
            if(indegree[i]==0)
                q.push(i);
        }
        vector<int> topo;
        while(!q.empty()){
            int node=q.front(); q.pop();
            topo.push_back(node);
            for(int neighbour:adj[node]){
                if(--indegree[neighbour]==0)
                    q.push(neighbour);
            }
        }
        return topo;
    }
};
