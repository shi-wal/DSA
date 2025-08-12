class Solution {
    bool dfs(vector<vector<char>>& board, string word, int row, int col, int w){
        if(w==word.length()) return true;
        int m=board.size(), n=board[0].size();

        if(row<0 || row>=m || col<0 || col>=n || board[row][col]!=word[w]) return false;

        char temp=board[row][col];
        board[row][col]='#';

        vector<int> dir={-1,0,1,0,-1};
        for(int i=0;i<4;i++){
            int newRow=row+dir[i], newCol=col+dir[i+1];
            if(dfs(board,word,newRow,newCol,w+1)) {
                board[row][col]=temp;
                return true;
            }
        }
        
        board[row][col]=temp;
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size(), n=board[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(dfs(board,word,i,j,0)) return true;
            }
        }
        return false;
    }
};
