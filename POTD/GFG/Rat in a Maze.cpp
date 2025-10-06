class Solution {
    void findPath(vector<vector<int>>& maze, int i, int j, int n, vector<string>& res,
    string path, vector<vector<bool>>& vis){
        if(i<0 || i>=n || j<0 || j>=n || vis[i][j] || maze[i][j]==0) return;
        if(i==n-1 && j==n-1){
            res.push_back(path);
            return;
        }
        vis[i][j]=true;
        findPath(maze,i+1,j,n,res,path+"D",vis);
        findPath(maze,i,j-1,n,res,path+"L",vis);
        findPath(maze,i,j+1,n,res,path+"R",vis);
        findPath(maze,i-1,j,n,res,path+"U",vis);
        vis[i][j]=false;
    }

  public:
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        vector<string> res;
        int n=maze.size();
        if(maze[0][0]==0 || maze[n-1][n-1]==0) return res;
        vector<vector<bool>> vis(n,vector<bool>(n,false));
        findPath(maze,0,0,n,res,"", vis);
        return res;
    }
};
