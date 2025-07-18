// Given a rod of length n inches and an array price[], where price[i] denotes the value of a piece of length i. 
// Your task is to determine the maximum value obtainable by cutting up the rod and selling the pieces.

// Recursion+Memoization

class Solution {
    int solveMem(vector<int> &price, int index, int n, vector<vector<int>> &dp){
        if(index==0) return n*price[0];
        if(dp[index][n]!=-1) return dp[index][n];
        int nottake=solveMem(price,index-1,n,dp);
        int take=INT_MIN;
        int rodlength=index+1;
        if(rodlength<=n) take=price[index]+solveMem(price,index,n-rodlength,dp);
        return dp[index][n]=max(take,nottake);
    }
  public:
    int cutRod(vector<int> &price) {
        int len=price.size();
        vector<vector<int>> dp(len,vector<int>(len+1,-1));
        return solveMem(price,len-1, len, dp);  --> for Rec+Mem
    }
};



// Tabulation+Space Optimization

class Solution {
  public:
    int cutRod(vector<int> &price) {
        int len=price.size();
        vector<int> prev(len+1,0), curr(len+1,0);
        for(int i=0;i<=len;i++) prev[i]=i*price[0];
        for(int i=1;i<len;i++){
            for(int j=1;j<=len;j++){
                int nottake=prev[j];
                int take=INT_MIN;
                int rodlength=i+1;
                if(rodlength<=j) take=price[i]+curr[j-rodlength];
                curr[j]=max(take,nottake);
            }
            prev=curr;
        }
        return  prev[len];
    }
};
