class Solution {
public:
    bool canJump(vector<int>& nums) {
        int target=nums.size()-1;
        for(int i=target-1;i>=0;i--){
            if(i+nums[i]>=target) target=i;
        }
        if(target==0) return true;
        return false;
    }
};
