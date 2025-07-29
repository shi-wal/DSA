class Solution {
    int eggDropHelper(int n, int k, vector<vector<int>> &dp){
        if(k==1 || k==0 || n==1) return k;
        if(dp[n][k]!=-1) return dp[n][k];
        int ans=INT_MAX;
        int low=1, high=k;
        while(low<=high){
            int mid=(low+high)/2;
            int case1=eggDropHelper(n-1,mid-1,dp); // egg breaks
            int case2=eggDropHelper(n,k-mid,dp); // egg survives
            int worst=max(case1,case2)+1; // throwing an egg is counted as 1 attempt hence adding 1
            if(case1<case2) low=mid+1;
            else high=mid-1;
            ans=min(ans,worst);
        }
        return dp[n][k]=ans; 
    }
  public:
    int eggDrop(int n, int k) {
        vector<vector<int>> dp(n+1,vector<int>(k+1,-1));
        return eggDropHelper(n,k,dp);
    }
};
