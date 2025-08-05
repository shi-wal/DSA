// TC: O(M*N), SC: O(M*N)

class Solution {
    vector<int> dir={-1,0,1,0,-1};
    void dfs(vector<vector<int>>& heights, int i, int j, int prev, vector<vector<bool>>& ocean){
        if(i<0 || i>=ocean.size() || j<0 || j>=ocean[0].size()) return;
        if(heights[i][j]<prev || ocean[i][j]) return;
        ocean[i][j]=true;
        for(int d=0;d<4;d++){
            dfs(heights,i+dir[d],j+dir[d+1],heights[i][j],ocean);
        }
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m=heights.size(), n=heights[0].size();
        vector<vector<int>> res;
        vector<vector<bool>> pacific(m,vector<bool>(n,false));
        vector<vector<bool>> atlantic(m,vector<bool>(n,false));
        //columns
        for(int col=0;col<n;col++){
            dfs(heights,0,col,INT_MIN,pacific);
            dfs(heights,m-1,col,INT_MIN,atlantic);
        }
        //rows
        for(int row=0;row<m;row++){
            dfs(heights,row,0,INT_MIN,pacific);
            dfs(heights,row,n-1,INT_MIN,atlantic);
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(pacific[i][j] && atlantic[i][j]) res.push_back({i,j});
            }
        }
        return res;
    }
};
