class Solution {
    bool solveMem(vector<int>& nums, int target, int i, vector<vector<int>> &dp){
        if(target==0) return true;
        int n=nums.size();
        if(target<0 || i>=n) return false;
        if(dp[i][target]!=-1) return dp[i][target];
        int incl=solveMem(nums,target-nums[i],i+1,dp);
        int excl=solveMem(nums,target,i+1,dp);
        return dp[i][target]=incl || excl;
    }
    bool check(vector<int>& nums, int target){
        int n=nums.size();
        vector<vector<bool>> dp(n+1,vector<bool>(target+1, false));
        for(int i=0;i<=n;i++) dp[i][0]=true;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=target;j++){
                if(j<nums[i-1]) dp[i][j]=dp[i-1][j];
                else{
                    int incl=dp[i-1][j-nums[i-1]];
                    int excl=dp[i-1][j];
                    dp[i][j]=incl || excl;
                }
            }
        }
        return dp[n][target];
    }
public:
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int num:nums) sum+=num;
        if(sum%2) return false;
        int n=nums.size();
        // vector<vector<int>> dp(n,vector<int>(sum/2+1, -1));
        // return solveMem(nums,sum/2,0,dp);
        return check(nums,sum/2);
    }
};
