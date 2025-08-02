class Solution {
public:
    int findMin(vector<int>& nums) {
        int left=0, right=nums.size()-1;
        int ans=INT_MAX;
        while(left<=right){
            int mid=(left+right)/2;
            if(nums[left]<=nums[right]) {
                ans=min(ans,nums[left]);
                break;
            }
            if(nums[left]<=nums[mid]){
                ans=min(ans,nums[left]);
                left=mid+1; // check in next sorted part
            }
            else {
                ans=min(ans,nums[mid]);
                right=mid-1; // case: [3,4,5,6,1,2] --> left=6, mid=1, right=2
            }
        }
        return ans;
    }
};
