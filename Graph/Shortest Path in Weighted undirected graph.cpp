// check this code if it runs or not

class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto edge:edges){
            adj[edge[0]].push_back({edge[1],edge[2]});
            adj[edge[1]].push_back({edge[0],edge[2]});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int> dist(n+1,INT_MAX), parent(n+1);
        dist[1]=0;
        for(int i=1;i<=n;i++) parent[i]=i;
        pq.push({0,1});
        while(!pq.empty()){
            auto it=pq.top(); pq.pop();
            int dis=it.first, node=it.second;
            if (dis > dist[node]) continue;
            for(auto neighbour:adj[node]){
                int adjNode=neighbour.first;
                int weight=neighbour.second;
                if(dis+weight<dist[adjNode]){
                    dist[adjNode]=dis+weight;
                    parent[adjNode]=node;
                    pq.push({dis+weight,adjNode});
                }
            }
        }
        if(dist[n]==INT_MAX) return {-1};
        vector<int> path;
        int node=n;
        while(parent[node]!=node){
            path.push_back(node);
            node=parent[node];
        }
        path.push_back(node);
        reverse(path.begin(),path.end());
        return path;
    }
};
