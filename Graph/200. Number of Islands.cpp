class Solution {
    void bfs(int row, int col, vector<vector<bool>>& vis, vector<vector<char>>& grid){
        vis[row][col]=true;
        queue<pair<int,int>> q;
        q.push({row,col});
        int m=grid.size(), n=grid[0].size();
        vector<int> dir={-1,0,1,0,-1};
        while(!q.empty()){
            int x=q.front().first, y=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int nrow=x+dir[i], ncol=y+dir[i+1];
                if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && grid[nrow][ncol]=='1' && !vis[nrow][ncol]){
                    vis[nrow][ncol]=true;
                    q.push({nrow,ncol});
                }
            }
        }
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size(), n=grid[0].size();
        vector<vector<bool>> vis(m,vector<bool>(n,false));
        int cnt=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1' && !vis[i][j]) {
                    cnt++;
                    bfs(i,j,vis,grid);
                }  
            }
        }
        return cnt;
    }
};
