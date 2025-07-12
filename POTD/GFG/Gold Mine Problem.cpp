class Solution {
    int dfs(vector<vector<int>>& mat, int i,int j, vector<vector<int>> &dp){
        int n=mat.size(), m=mat[0].size();
        int temp=0;
        // top right diagonal
        if(i-1>=0 && j+1<m){
            if(dp[i-1][j+1]!=-1) temp=max(temp,dp[i-1][j+1]);
            else temp=max(temp, dfs(mat,i-1,j+1,dp));
        }
        // right
        if(j+1<m){
            if(dp[i][j+1]!=-1) temp=max(temp,dp[i][j+1]);
            else temp=max(temp, dfs(mat,i,j+1,dp));
        }
        // bottom right diagonal
        if(i+1<n && j+1<m){
            if(dp[i+1][j+1]!=-1) temp=max(temp,dp[i+1][j+1]);
            else temp=max(temp, dfs(mat,i+1,j+1,dp));
        }
        dp[i][j]=temp+mat[i][j];
        return dp[i][j];
    }
  public:
    int maxGold(vector<vector<int>>& mat) {
        int n=mat.size(), m=mat[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        int ans=-1;
        for(int i=0;i<n;i++){
            int temp=dfs(mat,i,0,dp);
            ans=max(ans,temp);
        }
        return ans;
    }
};
