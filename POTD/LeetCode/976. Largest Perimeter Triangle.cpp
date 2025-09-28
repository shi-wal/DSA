class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        for(int i=n-1;i>1;i--){
            int j=i-1, k=j-1;
            if(nums[j]+nums[k]>nums[i]) return nums[i]+nums[j]+nums[k];
        }
        return 0;
    }
};
