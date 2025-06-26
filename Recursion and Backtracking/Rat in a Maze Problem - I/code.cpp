// for lexicographically order follow: D->L->R->U

class Solution {
    void solve(int row, int col, int n, vector<vector<int>>& maze, vector<string>& res, string move, vector<vector<bool>>& vis){
        if(row==n-1 && col==n-1){
            res.push_back(move); return;
        }
        vis[row][col]=true;
        //downward
        if(row+1<n && maze[row+1][col]==1 && !vis[row+1][col]){
            solve(row+1,col,n,maze,res,move+'D',vis);
        }
        //leftward
        if(col-1>=0 && maze[row][col-1]==1 && !vis[row][col-1]){
            solve(row,col-1,n,maze,res,move+'L',vis);
        }
        //rightward
        if(col+1<n && maze[row][col+1]==1 && !vis[row][col+1]){
            solve(row,col+1,n,maze,res,move+'R',vis);
        }
        //upward
        if(row-1>=0 && maze[row-1][col]==1 && !vis[row-1][col]){
            solve(row-1,col,n,maze,res,move+'U',vis);
        }
        vis[row][col]=false; //backtrack
    }
  public:
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        vector<string> res;
        int n=maze.size();
        vector<vector<bool>> vis(n, vector<bool>(n,false));
        if(maze[0][0]==1) solve(0,0,n,maze,res,"",vis);
        return res;
    }
};
