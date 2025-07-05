// You are given an array arr[] of integers. Your task is to find the maximum sum of the smallest and second smallest 
// elements across all subarrays (of size >= 2) of the given array.
// Approach: we can simply return maxSum of consecutive elements for this.

class Solution {
  public:
    int maxSum(vector<int> &arr) {
        int n=arr.size();
        int maxS=0;
        for(int i=1;i<n;i++)
            maxS=max(maxS,arr[i]+arr[i-1]);
        return maxS;
    }
};
