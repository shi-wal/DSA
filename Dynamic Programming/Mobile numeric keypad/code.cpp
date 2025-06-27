// TC: O(N)
class Solution {
    int solve(char keypad[4][3], int i, int j, int n, 
        vector<vector<vector<int>>>& dp){
        if(i<0 || i>=4 || j<0 || j>=3) return 0;
        if(keypad[i][j]=='*' || keypad[i][j]=='#') return 0;
        if(n==1) return 1;
        if(dp[i][j][n]!=-1) return dp[i][j][n];
        // Stay, Up, Left, Down, Right
        return dp[i][j][n]= solve(keypad,i,j,n-1,dp)+
                            solve(keypad,i-1,j,n-1,dp)+
                            solve(keypad,i,j-1,n-1,dp)+
                            solve(keypad,i+1,j,n-1,dp)+
                            solve(keypad,i,j+1,n-1,dp);
    }
  public:
    int getCount(int n) {
        char keypad[4][3]={{'1','2','3'},{'4','5','6'},
                            {'7','8','9'},{'*','0','#'}};
        int cnt=0;
        vector<vector<vector<int>>> dp(4, vector<vector<int>>(3,vector<int>(n+1,-1)));
        
        for(int i=0;i<4;i++){
            for(int j=0;j<3;j++){
               if(keypad[i][j]!='*' && keypad[i][j]!='#')
                cnt+=solve(keypad,i,j,n,dp);
            }
        }
        return cnt;
    }
};
