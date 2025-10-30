class Solution {
    bool isValid(int i, int j, int m, int n){
        return i>=0 && i<m && j>=0 && j<n;
    }
    void setNotClosed(int i, int j, int m, int n, vector<vector<char>>& grid){
        grid[i][j]='N';
        vector<int> dir={-1,0,1,0,-1};
        for(int d=0;d<4;d++){
            int ni=i+dir[d];
            int nj=j+dir[d+1];
            if(isValid(ni,nj,m,n) && grid[ni][nj]=='O') 
                setNotClosed(ni,nj,m,n,grid);
        }
    }
  public:
    void fill(vector<vector<char>>& grid) {
        int m=grid.size(), n=grid[0].size();
        for(int i=0;i<m;i++){
            if(grid[i][0]=='O') setNotClosed(i,0,m,n,grid);
            if(grid[i][n-1]=='O') setNotClosed(i,n-1,m,n,grid);
        }
        for(int i=0;i<n;i++){
            if(grid[0][i]=='O') setNotClosed(0,i,m,n,grid);
            if(grid[m-1][i]=='O') setNotClosed(m-1,i,m,n,grid);
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='O') grid[i][j]='X';
                if(grid[i][j]=='N') grid[i][j]='O';
            }
        }
    }
};
