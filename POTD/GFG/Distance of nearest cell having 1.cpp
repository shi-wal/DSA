class Solution {
  public:
    vector<vector<int>> nearest(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size();
        vector<vector<int>> ans(m,vector<int>(n,-1));
        queue<pair<int,int>> q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    q.push({i,j});
                    ans[i][j]=0;
                }
            }
        }
        vector<int> dir={-1,0,1,0,-1};
        while(!q.empty()){
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            for(int d=0;d<4;d++){
                int nx=x+dir[d];
                int ny=y+dir[d+1];
                if(nx>=0 && nx<m && ny>=0 && ny<n && ans[nx][ny]==-1){
                    q.push({nx,ny});
                    ans[nx][ny]=ans[x][y]+1;
                }
            }
        }
        return ans;
    }
};
