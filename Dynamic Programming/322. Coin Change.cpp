// Using Tabulation (Bottom-Up approach)

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,1e9));
        for(int a=0;a<=amount;a++) if(a%coins[0]==0) dp[0][a]=a/coins[0];
        for(int i=1;i<n;i++){
            for(int a=0;a<=amount;a++){
                int nottake=dp[i-1][a];
                int take=1e9;
                if(coins[i]<=a) take=1+dp[i][a-coins[i]];
                dp[i][a]=min(take,nottake);
            }
        }
        int ans=dp[n-1][amount];
        return ans>=1e9?-1:ans;
    }
};



// Space Optimized Version (1D DP)

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, 1e9);
        dp[0]=0;

        for(int coin:coins){
            for (int a=coin;a<=amount;++a) {
                dp[a]=min(dp[a], 1+dp[a-coin]);
            }
        }
        return dp[amount]==1e9?-1:dp[amount];
    }
};
