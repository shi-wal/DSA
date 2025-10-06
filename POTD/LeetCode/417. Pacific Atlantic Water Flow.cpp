class Solution {
    vector<int> dir={-1,0,1,0,-1};
    void dfs(int row, int col, int prev, vector<vector<bool>>& ocean, vector<vector<int>>& height){
        if(row<0 || row>=ocean.size() || col<0 || col>=ocean[0].size()) return;
        if(height[row][col]<prev || ocean[row][col]) return;
        ocean[row][col]=true;
        for(int d=0;d<4;d++){
            dfs(row+dir[d],col+dir[d+1],height[row][col],ocean,height);
        }
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m=heights.size(), n=heights[0].size();
        vector<vector<int>> res;
        vector<vector<bool>> pac(m,vector<bool>(n,false));
        vector<vector<bool>> atl(m,vector<bool>(n,false));
        for(int row=0;row<m;row++){
            dfs(row,0,INT_MIN,pac,heights);
            dfs(row,n-1,INT_MIN,atl,heights);
        }
        for(int col=0;col<n;col++){
            dfs(0,col,INT_MIN,pac,heights);
            dfs(m-1,col,INT_MIN,atl,heights);
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(pac[i][j] && atl[i][j]) res.push_back({i,j});
            }
        }
        return res;
    }
};
