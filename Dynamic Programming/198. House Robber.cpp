// Top-Down

class Solution {
    int dorob(vector<int>& nums, vector<int>& dp, int i, int n){
        if(i>=n) return 0;
        if(dp[i]!=-1) return dp[i];
        int take=nums[i]+dorob(nums,dp,i+2,n);
        int nottake=dorob(nums,dp,i+1,n);
        return dp[i]=max(take,nottake); 
    }
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,-1);
        return dorob(nums,dp,0,n);
    }
};

// Bottom-up

class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        vector<int> dp(n,0);
        dp[0]=nums[0]; dp[1]=max(nums[0],nums[1]);
        for(int i=2;i<n;i++){
            int take=nums[i]+dp[i-2];
            int nottake=dp[i-1];
            dp[i]=max(take,nottake);
        }
        return dp[n-1];
    }
};

// TC: O(n), SC:O(1)

class Solution {
public:
    int rob(vector<int>& nums) {
        int prev1=0, prev2=0;
        for(int num:nums){
            int temp=prev1;
            prev1=max(prev2+num, prev1);
            prev2=temp;
        }
        return prev1;
    }
};
