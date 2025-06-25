//TC: O(9^m) where m= # of empty cells.

class Solution {
    bool isValid(vector<vector<char>>& board, char c, int row, int col){
        for(int k=0;k<9;k++){
            //row check
            if(board[k][col]==c) return false;

            //col check
            if(board[row][k]==c) return false;

            // 3*3 matrix check
            if(board[3*(row/3) + k/3][3*(col/3) + k%3]==c) return false;
        }
        return true;
    }

    bool solve(vector<vector<char>>& board){
        for(int row=0;row<9;row++){
            for(int col=0;col<9;col++){
                if(board[row][col]=='.'){
                    for(char c='1'; c<='9'; c++){
                        if(isValid(board,c,row,col)){
                            board[row][col]=c;
                            if(solve(board))  return true;
                            else  board[row][col]='.';  // backtrack
                        }  
                    }
                    return false; //No correct value 1->9 can be found.
                }
            }
        }
        return true;
    }

public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};
