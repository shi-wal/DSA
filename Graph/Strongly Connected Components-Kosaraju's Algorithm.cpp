//Position this line where user code will be pasted.
class Solution {
    void topoSort(vector<vector<int>> &adj, stack<int> &st, vector<bool> &vis,int node){
        vis[node]=true;
        for(auto it:adj[node]){
            if(!vis[it]){
                topoSort(adj,st,vis,it);
            }
        }
        st.push(node);
    }
    void revDFS(vector<vector<int>> &transpose, vector<bool> &vis,int node){
        vis[node]=true;
        for(auto it:transpose[node]){
            if(!vis[it]){
                revDFS(transpose,vis,it);
            }
        }
    }
  public:
    int kosaraju(vector<vector<int>> &adj) {
        int n=adj.size();
        stack<int> st;
        vector<bool> vis(n,false);
        
        // Step1:
        for(int i=0;i<n;i++){
            if(!vis[i]){
                topoSort(adj,st,vis,i);
            }
        }
        
        // Step2:
        vector<vector<int>> transpose(n);
        for(int i=0;i<n;i++){
           vis[i]=false;
           for(auto it:adj[i])
                transpose[it].push_back(i); // reversing dir'n of edges
        }

        // Step3:
        int cnt=0;
        while(!st.empty()){
            int node=st.top(); st.pop();
            if(!vis[node]){
                cnt++;
                revDFS(transpose,vis,node);
            }
        }
        return cnt;
    }
};
