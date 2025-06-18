class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // ** 1st Approach **
        int maxSum=INT_MIN,sum=0;
        for(int x:nums){
            sum+=x;
            maxSum=max(maxSum,sum);
            if(sum<0) sum=0;
        }
        return maxSum;

        // ** 2nd Approach ** (Optimized by chatGPT)
        int maxSum = nums[0], sum = 0;
        for (int x : nums) {
            sum = max(x, sum + x);//-2,1,-2,4,3,5,6,1,5
            maxSum = max(maxSum, sum);//-2,1,4,5,6
        }
        return maxSum;
    }
};
