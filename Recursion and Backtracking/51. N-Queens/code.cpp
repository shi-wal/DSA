// TC: O(N!), SC:O(N^2)
// Myself with guidance

class Solution {
    bool isSafe(int row, int  col, int n, vector<string>& board){
        int r=row, c=col;
        while(r>=0 && c>=0){ //upper diagonal
            if(board[r][c]=='Q') return false;
            r--; c--;
        }
        r=row, c=col;
        while(r<n && c>=0){ //lower diagonal
            if(board[r][c]=='Q') return false;
            r++; c--;
        }
        while(col>=0){
            if(board[row][col]=='Q') return false;
            col--;
        }
        return true;
    }

    void solve(int col, int n, vector<string>& board, vector<vector<string>>& ans){
        if(col==n){
            ans.push_back(board);
            return;
        }
        for(int row=0;row<n;row++){
            if(isSafe(row,col,n,board)){
                board[row][col]='Q';
                solve(col+1,n,board,ans);
                board[row][col]='.';
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
        solve(0,n,board,ans);
        return ans;
    }
};
