class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int low=0, high=nums.size()-2; // high=n-2 to avoid out of bounds
        while(low<=high){
            int mid=(low+high)/2;
            if(nums[mid]==nums[mid^1]) 
                // mid ^ 1 swaps 0<->1, 2<->3, etc. So matches pair
                low=mid+1;
            else high=mid-1;
        }
        return nums[low];
    }
};
