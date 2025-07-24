class Solution {
    bool isPalind(int i,int j,string& s){
        while(i<j){
            if(s[i++]!=s[j--]) return false;
        }
        return true;
    }
    
    int helper(int i,int j,string& s,vector<vector<int>>& dp){
        if(i>=j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(isPalind(i,j,s)) return dp[i][j]=0;
        int mini=INT_MAX;
        for(int k=i;k<j;k++){
            if(isPalind(i,k,s)){ // s[i][k] is already palindrome
                int temp=1+helper(k+1,j,s,dp); // check for s[k+1][j]
                mini=min(mini,temp);
            }
        }
        return dp[i][j]=mini;
    }

  public:
    int palPartition(string &s) {
        int n=s.length();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return helper(0,n-1,s,dp);
    }
};
