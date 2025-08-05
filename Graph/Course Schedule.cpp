// There are a total of n tasks you have to pick, labelled from 0 to n-1. Some tasks may have prerequisites[][] tasks, 
// for example to pick task 0 you have to first finish tasks 1, which is expressed as a pair: [0, 1]
// Given the total number of n tasks and a list of prerequisite pairs of size m. Find a ordering of tasks you should pick to finish all tasks.

class Solution {
    bool cycle(int node, vector<vector<int>>& adj, vector<bool>& vis, 
    vector<bool>& recStack, vector<int>& order){
        vis[node]=true;
        recStack[node]=true;
        for(auto neigh:adj[node]){
            if(!vis[neigh])
                if(cycle(neigh,adj,vis,recStack,order)) return true;
            else if(recStack[neigh]) return true;
        }
        recStack[node]=false;
        order.push_back(node);
        return false;
    }
  public:
    vector<int> findOrder(int n, vector<vector<int>> prerequisites) {
        vector<vector<int>> adj(n);
        for (auto& p : prerequisites) {
            adj[p[1]].push_back(p[0]); // p[1] → p[0]
        }
        vector<bool> vis(n,false), recStack(n,false);
        vector<int> order;
        for(int i=0;i<n;i++){
            if(!vis[i]) if(cycle(i,adj,vis,recStack,order)) return {};
        }
        reverse(order.begin(),order.end()); // DFS topological sort requires reverse postorder, not preorder.
        return order;
    }
};
