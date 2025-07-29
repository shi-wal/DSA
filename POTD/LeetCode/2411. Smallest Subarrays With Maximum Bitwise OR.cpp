class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n=nums.size();
        vector<int> lastSeen(32, -1); // last seen index of each bit
        vector<int> ans(n);
        for(int i=n-1;i>=0;i--){
            for(int b=0;b<32;b++){
                if(nums[i] & (1<<b)) lastSeen[b]=i;
            }
            int farthest=i;
            for(int b=0;b<32;b++){
                if(lastSeen[b]!=-1) farthest=max(farthest,lastSeen[b]);
            }
            ans[i]=farthest-i+1;            
        }
        return ans;
    }
};
