// Using BFS
class Solution {
    bool detectCycle(int src, vector<vector<int>>& adjnode, vector<bool>& vis){
        vis[src]=true;
        queue<pair<int,int>> q;
        q.push({src,-1});
        while(!q.empty()){
            int node=q.front().first;
            int parent=q.front().second;
            q.pop();
            for(auto adj : adjnode[node]){
                if(!vis[adj]){
                    vis[adj]=true;
                    q.push({adj,node});
                }
                else if(parent!=adj) return true; // cycle detected
            }
        }
        return false;
    }
    
  public:
    bool isCycle(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adjnode(V);
        for(auto edge:edges){
            adjnode[edge[0]].push_back(edge[1]);
            adjnode[edge[1]].push_back(edge[0]);
        }
        vector<bool> vis(V,false);
        for(int i=0;i<V;i++){ // doing loop for checking if there are disconnected components
            if(!vis[i]) if(detectCycle(i,adjnode,vis)) return true;
        }
        return false;
    }
};


// Using DFS
class Solution {
    bool dfs(int src, int parent, vector<vector<int>>& adjnode, vector<bool>& vis){
        vis[src]=true;
        for(auto adj : adjnode[src]){
            if(!vis[adj]){
                if(dfs(adj,src,adjnode,vis)) return true;
                }
            else if(parent!=adj) return true; // cycle detected
        }
        return false;
    }
    
  public:
    bool isCycle(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adjnode(V);
        for(auto edge:edges){
            adjnode[edge[0]].push_back(edge[1]);
            adjnode[edge[1]].push_back(edge[0]);
        }
        vector<bool> vis(V,false);
        for(int i=0;i<V;i++){ // doing loop for checking if there are disconnected components
            if(!vis[i]) if(dfs(i,-1,adjnode,vis)) return true;
        }
        return false;
    }
};
