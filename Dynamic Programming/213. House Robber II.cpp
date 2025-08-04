// All houses at this place are arranged in a circle. That means the first house is the neighbor of the last one.
// Meanwhile, adjacent houses have a security system connected, and it will automatically contact the police if two adjacent houses were broken into on the same night.

class Solution {
    int getMax(vector<int>& nums,int start,int end){
        int prevRob=0,maxRob=0;
        for(int i=start;i<=end;i++){
            int temp=max(maxRob,prevRob+nums[i]);
            prevRob=maxRob;
            maxRob=temp;
        }
        return maxRob;
    }
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        return max(getMax(nums,0,n-2), getMax(nums,1,n-1));
    }
};
