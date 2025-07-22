class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_map<int,int> mp;
        int n=nums.size();
        int left=0,right=0, maxScore=0;
        int sum=0;
        while(right<n){
            if(mp.find(nums[right])!=mp.end() && mp[nums[right]]>=left){
                int prev=mp[nums[right]];
                while(left!=prev+1){
                    if(left<n) sum-=nums[left++];
                }
            }
            mp[nums[right]]=right;
            sum+=nums[right];
            maxScore=max(maxScore,sum);
            right++;
        }
        return maxScore;
    }
};
