// User function Template for C++
class Solution {
    static bool comp(const vector<int>& a, const vector<int>& b) {
        return a[2]<b[2];  // Compare based on weight (w)
    }
    int findParent(int u, vector<int> &parent){
        if(u==parent[u]) return u;
        return findParent(parent[u],parent);
    }
    void unionn(int u, int v, vector<int> &parent, vector<int> &rank){
        u=findParent(u,parent);
        v=findParent(v,parent);
        if(rank[u]<rank[v]) parent[u]=v;
        else if(rank[u]>rank[v]) parent[v]=u;
        else{
            parent[v]=u;
            rank[u]++;
        }
    }
  public:
    int kruskalsMST(int V, vector<vector<int>> &edges) {
        sort(edges.begin(),edges.end(),comp);
        vector<int> parent(V), rank(V,0);
        for(int i=0;i<V;i++) parent[i]=i;
        int costMST=0;
        for(auto it:edges){
           if(findParent(it[1],parent)!=findParent(it[0],parent)){
               costMST+=it[2];
               unionn(it[0],it[1],parent,rank);
           } 
        }
        return costMST;
    }
};
