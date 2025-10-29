class Solution {
    pair<int,int> bfs(int start, vector<vector<int>>& adj, int V){
        vector<int> dist(V,-1);
        queue<int> q;
        q.push(start);
        dist[start]=0;
        int farthest=start;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto& nbr:adj[node]){
                if(dist[nbr]==-1){
                    dist[nbr]=dist[node]+1;
                    q.push(nbr);
                    if(dist[nbr]>dist[farthest]) farthest=nbr;
                }
            }
        }
        return {farthest,dist[farthest]};
    }
  public:
    int diameter(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        vector<bool> vis1(V,false), vis2(V,false);
        for(auto& edge:edges){
            int u=edge[0], v=edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        auto start=bfs(0,adj,V);
        int nodeA=start.first;
        auto end=bfs(nodeA,adj,V);
        return end.second;
    }
};
