// Done myself in single run!
class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        while(nums.size()>1){
            int l=nums.size();
            for(int i=0;i<l-1;i++){
                nums[i]=(nums[i]+nums[i+1])%10;
            }
            nums.pop_back();
        }
        return nums[0];
    }
};
