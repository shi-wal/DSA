class Solution {
  public:
    void floydWarshall(vector<vector<int>> &dist) {
       int n=dist.size();
       for(int i=0;i<n;i++) dist[i][i]=0;
       for(int via=0;via<n;via++){
           for(int i=0;i<n;i++){
               for(int j=0;j<n;j++){
                   if(dist[i][via]<1e8 && dist[via][j]<1e8)
                        dist[i][j]=min(dist[i][j],dist[i][via]+dist[via][j]);
               }
           }
       }
    //   for(int i=0;i<n;i++)
    //     if(dist[i][i]<0) cout<<"-ve Cycle exists."
    }
};
