class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size(), unique=0;
        for(int i=1;i<n;i++){
            // update next of unique with curr element onlt if it is not equal to the current unique index element.
            if(nums[i]!=nums[unique]){
                nums[++unique]=nums[i];
            }
        }
        return unique+1;
    }
};
