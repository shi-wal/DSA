//TC: O(N!), SC:O(N^2)

class Solution {
    void solve(int col, int n, vector<string>& board, vector<vector<string>>& ans, vector<int>& leftRow, vector<int>& upperDiagonal, vector<int>& lowerDiagonal ){
        if(col==n){
            ans.push_back(board);
            return;
        }
        for(int row=0;row<n;row++){
            if(leftRow[row]==0 && lowerDiagonal[row+col]==0 && upperDiagonal[n-1+col-row]==0){
                board[row][col]='Q';
                leftRow[row]=1;
                lowerDiagonal[row+col]=1;
                upperDiagonal[n-1+col-row]=1;
                solve(col+1,n,board,ans,leftRow,upperDiagonal,lowerDiagonal);
                // Backtrack
                board[row][col]='.';
                leftRow[row]=0;
                lowerDiagonal[row+col]=0;
                upperDiagonal[n-1+col-row]=0;
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board;
        string s(n,'.');
        for(int i=0;i<n;i++){
            board.push_back(s);
        }
        vector<int> leftRow(n,0), upperDiagonal(2*n-1,0), lowerDiagonal(2*n-1,0);
        solve(0,n,board,ans,leftRow,upperDiagonal,lowerDiagonal);
        return ans;
    }
};
