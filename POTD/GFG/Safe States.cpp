class Solution {
  public:
    vector<int> safeNodes(int V, vector<vector<int>>& edges) {
        vector<int> outDeg(V,0),safe;
        vector<vector<int>> adj(V);
        for(auto edge:edges){
            adj[edge[1]].push_back(edge[0]); //graph edges reversed
            outDeg[edge[0]]++;
        }
        queue<int> q;
        for(int i=0;i<V;i++){
            if(outDeg[i]==0) {
                q.push(i);
            }
        }
        while(!q.empty()){
            int node=q.front();
            q.pop();
            safe.push_back(node);
            for(int& nbr:adj[node]){
                outDeg[nbr]--;
                if(outDeg[nbr]==0) q.push(nbr);
            }
        }
        return safe;
    }
};
