class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxVal=0;
        for(int num:nums) maxVal=max(maxVal,num);
        int maxLen=0, currLen=0;
        for(int num:nums){
            if(num==maxVal) currLen++;
            else {
                maxLen=max(maxLen,currLen);
                currLen=0;
            }
        }
        return max(maxLen,currLen);
    }
};
