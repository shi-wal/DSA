class Solution {
    int findWays(int r, int c, int m, int n, vector<vector<int>>& mat, int k,
     int sum, vector<vector<vector<int>>>& dp){
        if(r>=m || c>=n) return 0;
        sum+=mat[r][c];
        if(sum>k) return 0;
        if(r==m-1 && c==n-1) {
           return sum==k;
        }
        if(dp[r][c][sum]!=-1) return dp[r][c][sum];
        int down=findWays(r+1,c,m,n,mat,k,sum,dp);
        int right=findWays(r,c+1,m,n,mat,k,sum,dp);
        return dp[r][c][sum]=down+right;
    }
  public:
    int numberOfPath(vector<vector<int>>& mat, int k) {
        int m=mat.size(), n=mat[0].size();
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(k + 1, -1)));
        return findWays(0,0,m,n,mat,k,0,dp);
    }
};
