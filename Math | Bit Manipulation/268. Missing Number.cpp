class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        for(int i=1;i<=n;i++) ans^=i;
        for(int i=0;i<n;i++) ans^=nums[i]; // same no. will get zero which are avail in nums, only missing will remain as ans.
        return ans;
    }
};
