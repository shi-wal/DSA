// done myself only but got sliding approch idea from seeing 1 solution

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int left=0, right=0;
        int zeros=0, maxLen=0;
        while(right<nums.size()){
            if(nums[right]==0) zeros++;
            while(zeros>1){
                if(nums[left]==0) zeros--;
                left++;
            }
            maxLen=max(maxLen,right-left); // need to remove 1 element as 0
            right++;
        }
        return maxLen;
    }
};
