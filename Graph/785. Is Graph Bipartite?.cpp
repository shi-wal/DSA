// BFS Approach

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int V=graph.size();
        vector<int> color(V,-1);
        for(int i=0;i<V;i++){  // for checking multiple components
            if(color[i]==-1){
                queue<int> q;
                q.push(i);
                color[i]=0;
                while(!q.empty()){
                    int node=q.front(); q.pop();
                    for(auto it: graph[node]){
                        if(color[it]==-1) {
                            color[it]=!color[node];
                            q.push(it);
                        }
                        else if(color[it]==color[node]) return false;
                    }
                }
            }
        }
        return true;
    }
};


// DFS Approach
class Solution {
    bool dfs(vector<vector<int>>& graph, int col, vector<int>& color, int node){
        color[node]=col;
        for(auto it:graph[node]){
            if(color[it]==-1){
                if(dfs(graph,!col,color,it)==false) return false;
            }
            else if(color[it]==color[node]) return false;
        }
        return true;
    }

public:
    bool isBipartite(vector<vector<int>>& graph) {
        int V=graph.size();
        vector<int> color(V,-1);
        for(int i=0;i<V;i++){ 
            if(color[i]==-1){
                if(dfs(graph,0,color,i)==false) return false;
            }
        }
        return true;
    }
};
