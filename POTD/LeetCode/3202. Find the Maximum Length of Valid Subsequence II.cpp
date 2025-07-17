// not understood 
class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int n=nums.size();
        if(k==1) return n;
        int res=0;
        for(int j=0;j<k;j++){
            vector<int> dp(k,0);
            for(int i=0;i<n;i++){
                int mod=nums[i]%k;
                int pos=(j-mod+k)%k;
                dp[mod]=dp[pos]+1;
                res=max(res,dp[mod]);
            }
        }
        return res;
    }
};
