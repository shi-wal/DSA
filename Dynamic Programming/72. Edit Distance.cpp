// Using Recursion + Memoization -> TC: O(N*M), SC: O(N*M)

class Solution {
    int editDistance(string word1, string word2, int i, int j, vector<vector<int>> &dp){
        if(i<0) return j+1;
        if(j<0) return i+1;
        if(dp[i][j]!=-1) return dp[i][j];
        if(word1[i]==word2[j]) return dp[i][j]=editDistance(word1,word2,i-1,j-1,dp);
        else return dp[i][j]= 1 + min({editDistance(word1,word2,i,j-1,dp), //insert
                        editDistance(word1,word2,i-1,j,dp), //delete
                        editDistance(word1,word2,i-1,j-1,dp)}); //replace
    }
public:
    int minDistance(string word1, string word2) {
        int n=word1.length(), m=word2.length();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return editDistance(word1, word2,n-1,m-1,dp);
    }
};



// Using Tabulation -> TC: O(N*M), SC: O(N*M)

class Solution {
public:
    int minDistance(string word1, string word2) {
        int n=word1.length(), m=word2.length();
        vector<vector<int>> dp(n+1,vector<int>(m+1));
        for(int i=0;i<=n;i++) dp[i][0]=i;
        for(int j=0;j<=m;j++) dp[0][j]=j;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(word1[i-1]==word2[j-1]) dp[i][j]=dp[i-1][j-1];
                else dp[i][j]= 1 + min({dp[i][j-1], //insert
                        dp[i-1][j], //delete
                        dp[i-1][j-1]}); //replace
            }
        }
        return dp[n][m];
    }
};



// Space Optimization -> TC: O(N*M), SC: O(M)

class Solution {
public:
    int minDistance(string word1, string word2) {
        int n=word1.length(), m=word2.length();
        vector<int> prev(m+1), curr(m+1);
        for(int j=0;j<=m;j++) prev[j]=j;
        for(int i=1;i<=n;i++){
            curr[0]=i; // because everytime curr is updated it has ith no. of opr'n at 0th index in tabulation code.
            for(int j=1;j<=m;j++){
                if(word1[i-1]==word2[j-1]) curr[j]=prev[j-1];
                else curr[j]= 1 + min({curr[j-1], //insert
                        prev[j], //delete
                        prev[j-1]}); //replace
            }
            prev=curr;
        }
        return prev[m];
    }
};
