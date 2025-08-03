// Given an integer array coins[ ] representing different denominations of currency and an integer sum.
// find the number of ways you can make sum by using different combinations from coins[ ]. 

class Solution {
  public:
    int count(vector<int>& coins, int sum) {
        vector<int> dp(sum+1,0);
        dp[0]=1;
        for(int coin:coins)
            for(int a=coin;a<=sum;a++)
                dp[a]+=dp[a-coin];
        return dp[sum];
    }
};
